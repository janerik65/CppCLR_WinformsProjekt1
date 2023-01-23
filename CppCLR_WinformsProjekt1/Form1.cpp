#include "pch.h"
#include "Form1.h"
#include <math.h>
#include "SimBase.h"

//System::Void Integrer_Click(System::Object^ sender, System::EventArgs^ e) {
//};
//
//System::Void ChinesePopulation_Click(System::Object^ sender, System::EventArgs^ e) {
//};

System::Void CppCLRWinformsProjekt::Form1::Integrer_Click(System::Object^ sender, System::EventArgs^ e)
{
	//TODO: Sett riktig verdi på konstantene (hvis de er konstanter?)
	//Constants
	const double LEAKAGE_OUTFLOW = 17;
	const double CONVEYOR_OUTFLOW = 12;

	//INIT values
	//People
	double Adult_fertile = 300000000;
	double A_f_TransitT = 42;

	double Adult_not_fertile = 30000000;
	double A_n_f_TransitT = 10;

	double Children = 400000000;
	double C_TransitT = 17;

	double Elders = 70000000;
	double E_TransitT = 35;

	//Money
	double State_pension_fond = 0;

	double Birth_rate = 0.01; //TODO: I Setlla står det = TIME; Hva er tidsteget satt til i Stella?

	double Birth = Birth_rate * Adult_fertile; //Flytt beregningen til loopen

	double Salary_level = 1100;

	double Working_population = Adult_fertile + Adult_not_fertile; //Flytt beregningen til loopen
	double Tax_level = 0.13;
	double Income = Working_population * Salary_level * Tax_level;
	double Pension_level = 0.33;
	double Pension = Elders * Pension_level * Salary_level;
	double Elders_death = LEAKAGE_OUTFLOW;
	//??		LEAK ZONE = 0 % to 100 %
	double Death = CONVEYOR_OUTFLOW;
	double Adult_not_fertile_death = LEAKAGE_OUTFLOW;
	//??		LEAK ZONE = 0 % to 100 %
	double Getting_old = CONVEYOR_OUTFLOW;
	double Child_death = LEAKAGE_OUTFLOW;
	//??		LEAK ZONE = 0 % to 100 %
	double Growing_up = CONVEYOR_OUTFLOW;

	double Adult_fertile_death = LEAKAGE_OUTFLOW;
	//??		LEAK ZONE = 0 % to 100 %
	double No_more_children = CONVEYOR_OUTFLOW;

	double t = 0;
	double dt = 0.1; //TODO Sett denne i INIT seksjonen

	//jeh Arrayer for displaying
	double tArr[200];
	for (int i; i < 200; i++) tArr[i] = 0;

	//PensionFondArr[]
	for (int i = 0; i < 200; i++) {
		//{ RUNTIME EQUATIONS }
		//:s State_pension_fond(t) = State_pension_fond(t - dt) + (Income - Pesion) * dt { NON - NEGATIVE }
		State_pension_fond += (Income - Pension) * dt;

		//: l Adult_fertile(t) = Adult_fertile(t - dt) + (Growing_up - No_more_children - Adult_fertile_death) * dt { CONVEYOR }
		Adult_fertile += (Growing_up - No_more_children - Adult_fertile_death) * dt;

		//: l Adult_not_fertile(t) = Adult_not_fertile(t - dt) + (No_more_children - Getting_old - Adult_not_fertile_death) * dt { CONVEYOR }
		Adult_not_fertile += (No_more_children - Getting_old - Adult_not_fertile_death) * dt;

		//: l Children(t) = Children(t - dt) + (Birth - Growing_up - Child_death) * dt { CONVEYOR }
		Children += (Birth - Growing_up - Child_death) * dt;

		//: l Elders(t) = Elders(t - dt) + (Getting_old - Death - Elders_death) * dt { CONVEYOR }
		Elders += (Getting_old - Death - Elders_death) * dt;

		/*: c Birth_rate = GRAPH(TIME)
			(0, 0, 0, 0209003215434), (20, 0, 0, 0244372990354), (40, 0, 0, 0250803858521), (60, 0, 0, 0209003215434), (80, 0, 0, 0218649517685), (100, 0, 0, 0237942122186), (120, 0, 0, 0299035369775), (140, 0, 0, 0257234726688), (160, 0, 0, 0257234726688), (180, 0, 0, 0324758842444), (200, 0, 0, 032154340836)
		*/
		//Starter med en fast Birth_rate

		//	: f Birth = Birth_rate * Adult_fertile{ UNIFLOW }
		Birth = Birth_rate * Adult_fertile;

		//: c Working_population = Adult_fertile + Adult_not_fertile
		Working_population = Adult_fertile + Adult_not_fertile;

		//	: f Income = Working_population * Salary_level * Tax_level{ UNIFLOW }
		Income = Working_population * Salary_level * Tax_level;

		//	: f Pesion = Elders * Pesion_level * Salary_level{ UNIFLOW }
		Pension = Elders * Pension_level * Salary_level;

		//	: f Elders_death = LEAKAGE OUTFLOW
		Elders_death = LEAKAGE_OUTFLOW;

		double	LEAKAGE_FRACTION = 0.76; //TODO Flytt til init?
		Death = CONVEYOR_OUTFLOW;
		Adult_not_fertile_death = LEAKAGE_OUTFLOW;
		LEAKAGE_FRACTION = 0.14;
		Getting_old = CONVEYOR_OUTFLOW;
		Child_death = LEAKAGE_OUTFLOW;
		LEAKAGE_FRACTION = 0.16;
		Growing_up = CONVEYOR_OUTFLOW;
		Adult_fertile_death = LEAKAGE_OUTFLOW;
		LEAKAGE_FRACTION = 0.06;
		No_more_children = CONVEYOR_OUTFLOW;
	}
	//{ TIME SPECS }
	double STARTTIME = 0;
	double STOPTIME = 200;

	/*	DT = 0, 25
		INTEGRATION = RK2
		RUNMODE = NORMAL
		PAUSEINTERVAL = 0
	{ The model has 21 (21) variables(array expansion in parens).
	In root model and 0 additional modules with 0 sectors.
	Stocks: 5 (5) Flows : 11 (11) Converters : 5 (5)
	Constants : 11 (11) Equations : 5 (5) Graphicals : 1 (1)
	}*/


	return System::Void();
}

System::Void CppCLRWinformsProjekt::Form1::ChinesePopulation_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Test grafikken
		//Load chart
	double Age[2][NO_OF_STEPS_TO_STORE] = { { 0.4, 0.8, 1.2, 1.6, 2.0 }, {3.2,5.5,6.9,5.7,4.3} };
	//Display2(Age);

	//Constants
	const double LEAKAGE_OUTFLOW = 14;
	const double CONVEYOR_OUTFLOW = 14;

	//INIT values
	//People
	double Adult_fertile = 300000000;
	double A_f_TransitT = 42;

	double Adult_not_fertile = 30000000;
	double A_n_f_TransitT = 10;

	double Children = 400000000;
	double C_TransitT = 17;

	double Elders = 70000000;
	double E_TransitT = 35;

	//Money
	double State_pension_fond = 0;

	double Birth_rate = 0.01; //TODO: I Setlla står det = TIME; Hva er tidsteget satt til i Stella?

	double Birth = Birth_rate * Adult_fertile; //Flytt beregningen til loopen

	double Salary_level = 1100;

	double Working_population = Adult_fertile + Adult_not_fertile; //Flytt beregningen til loopen
	double Tax_level = 0.13;
	double Income = Working_population * Salary_level * Tax_level;
	double Pension_level = 0.33;
	double Pension = Elders * Pension_level * Salary_level;
	double Elders_death = LEAKAGE_OUTFLOW;
	//??		LEAK ZONE = 0 % to 100 %
	double Death = CONVEYOR_OUTFLOW;
	double Adult_not_fertile_death = LEAKAGE_OUTFLOW;
	//??		LEAK ZONE = 0 % to 100 %
	double Getting_old = CONVEYOR_OUTFLOW;
	double Child_death = LEAKAGE_OUTFLOW;
	//??		LEAK ZONE = 0 % to 100 %
	double Growing_up = CONVEYOR_OUTFLOW;

	double Adult_fertile_death = LEAKAGE_OUTFLOW;
	//??		LEAK ZONE = 0 % to 100 %
	double No_more_children = CONVEYOR_OUTFLOW;

	double t = 0;
	double dt = 0.1; //TODO Sett denne i INIT seksjonen

	//jeh Arrayer for displaying
	double tArr[NO_OF_STEPS_TO_STORE];
	for (int i; i < NO_OF_STEPS_TO_STORE; i++) tArr[i] = 0;

	double arrState_pension_fond[NO_OF_STEPS_TO_STORE];
	for (int i; i < NO_OF_STEPS_TO_STORE; i++) arrState_pension_fond[i] = 0;

	double arrCosinus[NO_OF_STEPS_TO_STORE];
	for (int i; i < NO_OF_STEPS_TO_STORE; i++) arrCosinus[i] = 0;

	//PensionFondArr[]
	for (int i = 0; i < NO_OF_STEPS; i++) {
		//{ RUNTIME EQUATIONS }
		tArr[i] = t;

		//:s State_pension_fond(t) = State_pension_fond(t - dt) + (Income - Pesion) * dt { NON - NEGATIVE }
		State_pension_fond += (Income - Pension) * dt;
		arrState_pension_fond[i] = State_pension_fond;

		//TEST jeh
		/*double dSinus = sin(t);
		arrState_pension_fond[i] = dSinus;
		arrCosinus[i] = cos(t);*/

		//: l Adult_fertile(t) = Adult_fertile(t - dt) + (Growing_up - No_more_children - Adult_fertile_death) * dt { CONVEYOR }
		Adult_fertile += (Growing_up - No_more_children - Adult_fertile_death) * dt;

		//: l Adult_not_fertile(t) = Adult_not_fertile(t - dt) + (No_more_children - Getting_old - Adult_not_fertile_death) * dt { CONVEYOR }
		Adult_not_fertile += (No_more_children - Getting_old - Adult_not_fertile_death) * dt;

		//: l Children(t) = Children(t - dt) + (Birth - Growing_up - Child_death) * dt { CONVEYOR }
		Children += (Birth - Growing_up - Child_death) * dt;

		//: l Elders(t) = Elders(t - dt) + (Getting_old - Death - Elders_death) * dt { CONVEYOR }
		Elders += (Getting_old - Death - Elders_death) * dt;

		/*: c Birth_rate = GRAPH(TIME)
			(0, 0, 0, 0209003215434), (20, 0, 0, 0244372990354), (40, 0, 0, 0250803858521), (60, 0, 0, 0209003215434), (80, 0, 0, 0218649517685), (100, 0, 0, 0237942122186), (120, 0, 0, 0299035369775), (140, 0, 0, 0257234726688), (160, 0, 0, 0257234726688), (180, 0, 0, 0324758842444), (200, 0, 0, 032154340836)
		*/
		//Starter med en fast Birth_rate

		//	: f Birth = Birth_rate * Adult_fertile{ UNIFLOW }
		Birth = Birth_rate * Adult_fertile;

		//: c Working_population = Adult_fertile + Adult_not_fertile
		Working_population = Adult_fertile + Adult_not_fertile;

		//	: f Income = Working_population * Salary_level * Tax_level{ UNIFLOW }
		Income = Working_population * Salary_level * Tax_level;

		//	: f Pesion = Elders * Pesion_level * Salary_level{ UNIFLOW }
		Pension = Elders * Pension_level * Salary_level;

		//	: f Elders_death = LEAKAGE OUTFLOW
		Elders_death = LEAKAGE_OUTFLOW;

		double	LEAKAGE_FRACTION = 0.76; //TODO Flytt til init?
		Death = CONVEYOR_OUTFLOW;
		Adult_not_fertile_death = LEAKAGE_OUTFLOW;
		LEAKAGE_FRACTION = 0.14;
		Getting_old = CONVEYOR_OUTFLOW;
		Child_death = LEAKAGE_OUTFLOW;
		LEAKAGE_FRACTION = 0.16;
		Growing_up = CONVEYOR_OUTFLOW;
		Adult_fertile_death = LEAKAGE_OUTFLOW;
		LEAKAGE_FRACTION = 0.06;
		No_more_children = CONVEYOR_OUTFLOW;

		t += dt;
	}
	//{ TIME SPECS }
	double STARTTIME = 0;
	double STOPTIME = 200;

	/*Display2(tArr, arrState_pension_fond, arrCosinus, NO_OF_STEPS_TO_STORE);*/
	Display2(tArr, arrState_pension_fond, NO_OF_STEPS_TO_STORE);
	return System::Void();
}

bool CppCLRWinformsProjekt::Form1::Display2(double d2dArr[2][NO_OF_STEPS_TO_STORE])
{
	//int len = sizeof(2d2Arr[0]);
	//TEST jeh
	//double arrZZZ[2][5]{ {1,2,3,4,5},{0,1.2,3.5,6,2} };

	for (int i = 0; i < NO_OF_STEPS_TO_STORE; i++) {
		this->chart1->Series["Age"]->Points->AddXY(d2dArr[0][i], d2dArr[1][i]);
	}
	return false;
}

bool CppCLRWinformsProjekt::Form1::Display2(double dXArr[NO_OF_STEPS_TO_STORE], double dYArr[NO_OF_STEPS_TO_STORE], int NoOfStepsToDisplay)
{
	//int len = sizeof(2d2Arr[0]);
	for (int i = 0; i < NoOfStepsToDisplay; i++) {
		this->chart1->Series["Age"]->Points->AddXY(dXArr[i], dYArr[i]);
	}
	return false;
}

bool CppCLRWinformsProjekt::Form1::Display2(double dXArr[NO_OF_STEPS_TO_STORE], double dYArr[NO_OF_STEPS_TO_STORE], double dYArr2[NO_OF_STEPS_TO_STORE], int NoOfStepsToDisplay)
{
	//int len = sizeof(2d2Arr[0]);
	for (int i = 0; i < NoOfStepsToDisplay; i++) {
		//this->chart1->Series["Age"]->Color = Color::Blue;
		this->chart1->Series["Age"]->Points->AddXY(dXArr[i], dYArr[i]);
		this->chart1->Series["Age"]->Points[i]->Color = Color::Blue;
		auto col = this->chart1->Series["Age"]->Color;
		//this->chart1->Series["Age"]->Color = Color::Red;
		//this->chart1->ResetForeColor();
		this->chart1->Series["Age"]->Points->AddXY(dXArr[i], dYArr2[i]);
		this->chart1->Series["Age"]->Points[i]->Color = Color::Red;
	}
	return false;
}

System::Void CppCLRWinformsProjekt::Form1::jeh_Click(System::Object^ sender, System::EventArgs^ e)
{
	//TEST
	double dArr[2][NO_OF_STEPS_TO_STORE];
	SimBase^ sim = gcnew(SimBase);
	sim->PopultaionSim(dArr);
	//Display som graf
	bool bNyOK=Display2(dArr);
	return System::Void();

	//INTEGRATION = EULER
	//RUNMODE = NORMAL
	//{ INITIALIZATION EQUATIONS }
	double Population = 100;
	double Birth = Population * 0.001;
	double Death = Population * 0.01;
	double dt = 1;
	//{ TIME SPECS }
	int STARTTIME = 1;
	int	STOPTIME = 200;

	double xAkse[200];
	for (int i = 0; i < 200; i++) xAkse[i] = 0;
	double Y1Akse[200];
	for (int i = 0; i < 200; i++) Y1Akse[i] = 0;

	xAkse[0] = 0;
	Y1Akse[0] = Population;
	//{ RUNTIME EQUATIONS }
	for (int t = STARTTIME; t < STOPTIME; t++) {
		Population = Population + (Birth - Death) * dt;
		Birth = Population * 0.001;
		Death = Population * 0.01;
		xAkse[t] = t;
		Y1Akse[t] = Population;
	}

	bool bOKk = Display2(xAkse, Y1Akse, 200);
	return System::Void();
}
