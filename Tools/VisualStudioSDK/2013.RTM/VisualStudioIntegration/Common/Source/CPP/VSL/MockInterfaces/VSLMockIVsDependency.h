/***************************************************************************

Copyright (c) Microsoft Corporation. All rights reserved.
This code is licensed under the Visual Studio SDK license terms.
THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.

This code is a part of the Visual Studio Library.

***************************************************************************/

#ifndef IVSDEPENDENCY_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
#define IVSDEPENDENCY_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5

#if _MSC_VER > 1000
#pragma once
#endif

#include "vsshell.h"

#pragma warning(push)
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // can never be instantiated - user defined constructor required
#pragma warning(disable : 4512) // assignment operator could not be generated
#pragma warning(disable : 6011) // Dereferencing NULL pointer (a NULL derference is just another kind of failure for a unit test

namespace VSL
{

class IVsDependencyNotImpl :
	public IVsDependency
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IVsDependencyNotImpl)

public:

	typedef IVsDependency Interface;

	STDMETHOD(get_CanonicalName)(
		/*[out]*/ BSTR* /*pbstrCanonicalName*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(get_Type)(
		/*[out]*/ GUID* /*pguidType*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(get_Description)(
		/*[out]*/ BSTR* /*pbstrDescription*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(get_HelpContext)(
		/*[out]*/ DWORD* /*pdwHelpContext*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(get_HelpFile)(
		/*[out]*/ BSTR* /*pbstrHelpFile*/)VSL_STDMETHOD_NOTIMPL
};

class IVsDependencyMockImpl :
	public IVsDependency,
	public MockBase
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IVsDependencyMockImpl)

public:

VSL_DEFINE_MOCK_CLASS_TYPDEFS(IVsDependencyMockImpl)

	typedef IVsDependency Interface;
	struct get_CanonicalNameValidValues
	{
		/*[out]*/ BSTR* pbstrCanonicalName;
		HRESULT retValue;
	};

	STDMETHOD(get_CanonicalName)(
		/*[out]*/ BSTR* pbstrCanonicalName)
	{
		VSL_DEFINE_MOCK_METHOD(get_CanonicalName)

		VSL_SET_VALIDVALUE_BSTR(pbstrCanonicalName);

		VSL_RETURN_VALIDVALUES();
	}
	struct get_TypeValidValues
	{
		/*[out]*/ GUID* pguidType;
		HRESULT retValue;
	};

	STDMETHOD(get_Type)(
		/*[out]*/ GUID* pguidType)
	{
		VSL_DEFINE_MOCK_METHOD(get_Type)

		VSL_SET_VALIDVALUE(pguidType);

		VSL_RETURN_VALIDVALUES();
	}
	struct get_DescriptionValidValues
	{
		/*[out]*/ BSTR* pbstrDescription;
		HRESULT retValue;
	};

	STDMETHOD(get_Description)(
		/*[out]*/ BSTR* pbstrDescription)
	{
		VSL_DEFINE_MOCK_METHOD(get_Description)

		VSL_SET_VALIDVALUE_BSTR(pbstrDescription);

		VSL_RETURN_VALIDVALUES();
	}
	struct get_HelpContextValidValues
	{
		/*[out]*/ DWORD* pdwHelpContext;
		HRESULT retValue;
	};

	STDMETHOD(get_HelpContext)(
		/*[out]*/ DWORD* pdwHelpContext)
	{
		VSL_DEFINE_MOCK_METHOD(get_HelpContext)

		VSL_SET_VALIDVALUE(pdwHelpContext);

		VSL_RETURN_VALIDVALUES();
	}
	struct get_HelpFileValidValues
	{
		/*[out]*/ BSTR* pbstrHelpFile;
		HRESULT retValue;
	};

	STDMETHOD(get_HelpFile)(
		/*[out]*/ BSTR* pbstrHelpFile)
	{
		VSL_DEFINE_MOCK_METHOD(get_HelpFile)

		VSL_SET_VALIDVALUE_BSTR(pbstrHelpFile);

		VSL_RETURN_VALIDVALUES();
	}
};


} // namespace VSL

#pragma warning(pop)

#endif // IVSDEPENDENCY_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
