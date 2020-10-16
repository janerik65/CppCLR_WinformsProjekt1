#include "pch.h"
#include "Form1.h"
#include "SimBase.h"


bool SimBase::PopultaionSim(double dXArr[2][NO_OF_STEPS_TO_STORE])
{
	const int CHILD_YEAR = 17;
	const int AFERTIL_YEAR = 42;
	const float BIRTH_RATE = 0.03f;

	//Lagringsstrukturer
	float arrChild[CHILD_YEAR]{};
	float arrAFertil[AFERTIL_YEAR]{};

	float popChild{};
	float popFAdult{};
	float popTot{};

	double TEST;
	TEST = 41 / 2;
	TEST = 41 / 2.f;
	TEST = 41.5 * (1. / 2.);

	//Init population
	for (int ix = 0; ix < CHILD_YEAR; ix++) arrChild[ix] = 400.0f/17.0f;
	for (int ix = 0; ix < AFERTIL_YEAR; ix++) arrAFertil[ix] = 300.04/42.0f;
	

	//Summerer 
	for (int ix = 0; ix < CHILD_YEAR; ix++) 	popChild  += arrChild[ix];
	for (int ix = 0; ix < AFERTIL_YEAR; ix++)	popFAdult += arrAFertil[ix];
	popTot = popChild + popFAdult;

	//Simulerings -loop
	for (int ix = 0; ix < NO_OF_STEPS_TO_STORE; ix++) {
		
		//Shift arrayene ett år oppover og beregner nyfødte
		float NyAdult = arrChild[CHILD_YEAR - 1];
		for (int ixc = CHILD_YEAR-1; ixc > 0; ixc--) arrChild[ixc] = arrChild[ixc-1];
		for (int ixa = AFERTIL_YEAR-1; ixa > 0; ixa--) arrAFertil[ixa] = arrAFertil[ixa-1];
		arrAFertil[0] = NyAdult;
		arrChild[0] = BIRTH_RATE* popFAdult;

		//Dødlighet. 16% dør før de blir voksne. 20% av de voksne dør før de blir infertile
		for (int ix = 0; ix < CHILD_YEAR; ix++) arrChild[ix] -= arrChild[ix]*(0.16f/17.0f);
		for (int ix = 0; ix < AFERTIL_YEAR; ix++) arrAFertil[ix] -= arrAFertil[ix] * (0.2f / AFERTIL_YEAR);

		//Beregner populasjonen ved å summere årsklassene
		popChild = popFAdult = 0;
		for (int ix = 0; ix < CHILD_YEAR; ix++) 	popChild += arrChild[ix];
		for (int ix = 0; ix < AFERTIL_YEAR; ix++)	popFAdult += arrAFertil[ix];
		popTot = popChild + popFAdult;

		//Lagre i arrayet som returneres
		dXArr[0][ix] = ix;
		dXArr[1][ix] = popChild;
		int venteidebugger = ix;
	}


	return true;
}//END SimBase::PopultaionSim

bool SimBase::Display2(double dXArr[NO_OF_STEPS_TO_STORE], double dYArr[NO_OF_STEPS_TO_STORE], double dYArr2[NO_OF_STEPS_TO_STORE], int NoOfStepsToDisplay)
{
	//int len = sizeof(2d2Arr[0]);
	/*for (int i = 0; i < NoOfStepsToDisplay; i++) {
		//this->chart1->Series["Age"]->Color = Color::Blue;
		CppCLRWinformsProjekt::Form1::->chart1->Series["Age"]->Points->AddXY(dXArr[i], dYArr[i]);
		this->chart1->Series["Age"]->Points[i]->Color = Color::Blue;
		auto col = this->chart1->Series["Age"]->Color;
		//this->chart1->Series["Age"]->Color = Color::Red;
		//this->chart1->ResetForeColor();
		this->chart1->Series["Age"]->Points->AddXY(dXArr[i], dYArr2[i]);
		this->chart1->Series["Age"]->Points[i]->Color = Color::Red;
	}*/
	return false;
}
