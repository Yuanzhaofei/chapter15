#include"Base.h"
int main() {
	Pub_Derv pubd;
	Base *pdp = &pubd;
	Protected_Derv prod;
	//pdp = &prod;
	Private_Derv prid;
	//pdp = &prid;
	Derived_from_Public pubdd;
	pdp = &pubdd;
	Derived_from_Protected prodd;
	//pdp = &prodd;
	Derived_from_Private pridd;
	//pdp = &pridd;

}