#ifndef INCLUDED_Interface
#define INCLUDED_Interface

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Interface)


class HXCPP_CLASS_ATTRIBUTES  Interface_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef Interface_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual ::String lookAndSay( ::String s)=0;
		Dynamic lookAndSay_dyn();
virtual bool isValidEmail( ::String email)=0;
		Dynamic isValidEmail_dyn();
virtual int FibIter( int limit)=0;
		Dynamic FibIter_dyn();
virtual Void findOpenLockers( int n)=0;
		Dynamic findOpenLockers_dyn();
};

#define DELEGATE_Interface \
virtual ::String lookAndSay( ::String s) { return mDelegate->lookAndSay(s);}  \
virtual Dynamic lookAndSay_dyn() { return mDelegate->lookAndSay_dyn();}  \
virtual bool isValidEmail( ::String email) { return mDelegate->isValidEmail(email);}  \
virtual Dynamic isValidEmail_dyn() { return mDelegate->isValidEmail_dyn();}  \
virtual int FibIter( int limit) { return mDelegate->FibIter(limit);}  \
virtual Dynamic FibIter_dyn() { return mDelegate->FibIter_dyn();}  \
virtual Void findOpenLockers( int n) { return mDelegate->findOpenLockers(n);}  \
virtual Dynamic findOpenLockers_dyn() { return mDelegate->findOpenLockers_dyn();}  \


template<typename IMPL>
class Interface_delegate_ : public Interface_obj
{
	protected:
		IMPL *mDelegate;
	public:
		Interface_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_Interface
};


#endif /* INCLUDED_Interface */ 
