#pragma once
//forward Form1;
ref class SimBase
{
public: 
	bool PopultaionSim(double dXArr[2][NO_OF_STEPS_TO_STORE]);
	//void Sim1(Form1* form);
   bool Display2(double dXArr[NO_OF_STEPS_TO_STORE], double dYArr[NO_OF_STEPS_TO_STORE], double dYArr2[NO_OF_STEPS_TO_STORE], int NoOfStepsToDisplay);


};

