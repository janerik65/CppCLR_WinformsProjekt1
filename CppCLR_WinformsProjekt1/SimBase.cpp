#include "pch.h"
#include "Form1.h"
#include "SimBase.h"


bool SimBase::PopultaionSim(double dXArr[2][NO_OF_STEPS_TO_STORE])
{
	const int CHILD_YEAR = 17;
	const int AFERTIL_YEAR = 42;
	const int ANOTF_YEAR = 10;
	const int ELDERS_YEAR = 35;

	const float INIT_CHILD_POP = 400.;
	const float INIT_AFERTIL_POP = 300;
	const float INIT_ANOTF_POP = 30.;
	const float INIT_ELDERS_POP = 70.;

	const float BIRTH_RATE = 0.03;
	const float CHILD_DEATH_RATE = 0.06;
	const float AFERTIL_DEATH_RATE = 0.16;
	const float ANOTF_DEATH_RATE = 0.14;
	const float ELDERS_DEATH_RATE = 0.76;

	//Lagringsstrukturer
	float arrChild[CHILD_YEAR]{};
	float arrAFertil[AFERTIL_YEAR]{};
	float arrANotF[ANOTF_YEAR]{};
	float arrElders[ELDERS_YEAR]{};


	float popChild{};
	float popFAdult{};
	float popANotF{};
	float popElders{};
	float popTot{};

	//Init population, fordele dem likt på årene
	for (int ix = 0; ix < CHILD_YEAR; ix++) arrChild[ix] = INIT_CHILD_POP / CHILD_YEAR;
	for (int ix = 0; ix < AFERTIL_YEAR; ix++) arrAFertil[ix] = INIT_AFERTIL_POP / AFERTIL_YEAR;
	for (int ix = 0; ix < ANOTF_YEAR; ix++) arrANotF[ix] = INIT_ANOTF_POP / ANOTF_YEAR;
	for (int ix = 0; ix < ELDERS_YEAR; ix++) arrElders[ix] = INIT_ELDERS_POP / ELDERS_YEAR;

	//Summerer populasjon for hver gruppe
	for (int ix = 0; ix < CHILD_YEAR; ix++) 	popChild  += arrChild[ix];
	for (int ix = 0; ix < AFERTIL_YEAR; ix++)	popFAdult += arrAFertil[ix];
	for (int ix = 0; ix < ANOTF_YEAR; ix++)		popANotF  += arrANotF[ix];
	for (int ix = 0; ix < ELDERS_YEAR; ix++)	popElders += arrElders[ix];
	popTot = popChild + popFAdult + popANotF + popElders;

	//Simulerings -loop
	for (int ix = 0; ix < NO_OF_STEPS_TO_STORE; ix++) {
		
		//Ta vare på siste element i hvert array før en skifter en til høyre (untatt Elders, de blir bare borte)
		float NyAFertil = arrChild[CHILD_YEAR - 1];
		float NyANotF	= arrAFertil[AFERTIL_YEAR - 1];
		float NyElders	= arrANotF[ANOTF_YEAR - 1];

		//Shift arrayene ett år oppover og beregner nyfødte
		for (int ixc = CHILD_YEAR-1; ixc > 0; ixc--) arrChild[ixc] = arrChild[ixc-1];
		for (int ixa = AFERTIL_YEAR-1; ixa > 0; ixa--) arrAFertil[ixa] = arrAFertil[ixa-1];
		for (int ixa = ANOTF_YEAR - 1; ixa > 0; ixa--) arrANotF[ixa] = arrANotF[ixa - 1];
		for (int ixa = ELDERS_YEAR - 1; ixa > 0; ixa--) arrElders[ixa] = arrElders[ixa - 1];

		//Sett inn nye data først i hvert array (hver gruppe)
		arrChild[0] = BIRTH_RATE* popFAdult;
		arrAFertil[0] = NyAFertil;
		arrANotF[0] = NyANotF;
		arrElders[0] = NyElders;

		//Dødlighet. 16% dør før de blir voksne. 20% av de voksne dør før de blir infertile
		for (int ix = 0; ix < CHILD_YEAR; ix++) arrChild[ix] -= arrChild[ix]*(CHILD_DEATH_RATE/CHILD_YEAR);
		for (int ix = 0; ix < AFERTIL_YEAR; ix++) arrAFertil[ix] -= arrAFertil[ix] * (AFERTIL_DEATH_RATE/AFERTIL_YEAR);
		for (int ix = 0; ix < ANOTF_YEAR; ix++) arrANotF[ix] -= arrANotF[ix] * (ANOTF_DEATH_RATE / ANOTF_YEAR);
		for (int ix = 0; ix < ELDERS_YEAR; ix++) arrElders[ix] -= arrElders[ix] * (ELDERS_DEATH_RATE / ELDERS_YEAR);

		//Beregner populasjonen ved å summere årsklassene
		popChild = popFAdult = popANotF = popElders = 0;
		for (int ix = 0; ix < CHILD_YEAR; ix++) 	popChild += arrChild[ix];
		for (int ix = 0; ix < AFERTIL_YEAR; ix++)	popFAdult += arrAFertil[ix];
		for (int ix = 0; ix < ANOTF_YEAR; ix++)	popANotF += arrANotF[ix];
		for (int ix = 0; ix < ELDERS_YEAR; ix++)	popElders += arrElders[ix];
		popTot = popChild + popFAdult + popANotF + popElders;

		//Lagre i arrayet som returneres
		dXArr[0][ix] = ix;
		dXArr[1][ix] = popElders;
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
