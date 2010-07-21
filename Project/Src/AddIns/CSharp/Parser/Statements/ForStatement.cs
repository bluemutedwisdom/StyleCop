//-----------------------------------------------------------------------
// <copyright file="ForStatement.cs" company="Microsoft">
//     Copyright (c) Microsoft Corporation. All rights reserved.
// </copyright>
// <license>
//   This source code is subject to terms and conditions of the Microsoft 
//   Public License. A copy of the license can be found in the License.html 
//   file at the root of this distribution. If you cannot locate the  
//   Microsoft Public License, please send an email to dlr@microsoft.com. 
//   By using this source code in any fashion, you are agreeing to be bound 
//   by the terms of the Microsoft Public License. You must not remove this 
//   notice, or any other, from this software.
// </license>
//-----------------------------------------------------------------------
namespace Microsoft.StyleCop.CSharp
{
    using System;
    using System.Collections.Generic;
    using System.Diagnostics;

    /// <summary>
    /// A for-statement.
    /// </summary>
    /// <subcategory>statement</subcategory>
    public sealed class ForStatement : Statement
    {
        #region Private Fields

        /// <summary>
        /// The variables initialized in the for-statement.
        /// </summary>
        private ICollection<Expression> initializers;

        /// <summary>
        /// The condition checked before each loop through the for-statement.
        /// </summary>
        private Expression condition;

        /// <summary>
        /// The statements called at the end of each loop through the for-statement,
        /// used to advance the enumerator.
        /// </summary>
        private ICollection<Expression> iterators;

        /// <summary>
        /// The statement that is embedded within this for-statement.
        /// </summary>
        private Statement embeddedStatement;

        #endregion Private Fields

        #region Internal Constructors

        /// <summary>
        /// Initializes a new instance of the ForStatement class.
        /// </summary>
        /// <param name="proxy">Proxy object for the statement.</param>
        /// <param name="initializers">The variables declared in the for-statement declaration.</param>
        /// <param name="condition">The condition expression.</param>
        /// <param name="iterators">The iterator expressions.</param>
        internal ForStatement(
            CodeUnitProxy proxy,
            ICollection<Expression> initializers,
            Expression condition,
            ICollection<Expression> iterators)
            : base(proxy, StatementType.For)
        {
            Param.AssertNotNull(proxy, "proxy");
            Param.AssertNotNull(initializers, "initializers");
            Param.Ignore(condition);
            Param.AssertNotNull(iterators, "iterators");
            
            this.initializers = initializers;
            this.condition = condition;
            this.iterators = iterators;

            Debug.Assert(initializers.IsReadOnly, "The collection of initializers should be read-only.");
            Debug.Assert(iterators.IsReadOnly, "The collection of iterators should be read-only.");
        }

        #endregion Internal Constructors
    
        #region Public Properties

        /// <summary>
        /// Gets the variables declared in the for-statement declaration.
        /// </summary>
        public ICollection<Expression> Initializers
        {
            get
            {
                return this.initializers;
            }
        }

        /// <summary>
        /// Gets the condition checked before each loop through the for-statement.
        /// </summary>
        public Expression Condition
        {
            get
            {
                return this.condition;
            }
        }

        /// <summary>
        /// Gets the expressions called at the end of each loop through the for-statement,
        /// used to advance the enumerator.
        /// </summary>
        public ICollection<Expression> Iterators
        {
            get
            {
                return this.iterators;
            }
        }

        /// <summary>
        /// Gets the statement that is embedded within this for-statement.
        /// </summary>
        public Statement EmbeddedStatement
        {
            get
            {
                return this.embeddedStatement;
            }

            internal set
            {
                Param.AssertNotNull(value, "EmbeddedStatement");
                this.embeddedStatement = value;
            }
        }

        #endregion Public Properties

        #region Public Override Methods

        /// <summary>
        /// Gets the variables defined within this code unit.
        /// </summary>
        /// <returns>Returns the collection of variables.</returns>
        public override IVariable[] GetVariables()
        {
            if (this.initializers == null || this.initializers.Count == 0)
            {
                return null;
            }

            var variables = new List<IVariable>(this.initializers.Count);

            foreach (Expression initializerExpression in this.initializers)
            {
                if (initializerExpression.Is(ExpressionType.VariableDeclaration))
                {
                    variables.AddRange(((VariableDeclarationExpression)initializerExpression).GetVariables());
                }
            }

            return variables.ToArray();
        }

        #endregion Public Override Methods
    }
}