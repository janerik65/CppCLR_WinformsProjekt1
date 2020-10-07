#pragma once

//TODO: Sett riktig verdi på konstantene (hvis de er konstanter?)
const int NO_OF_STEPS_TO_STORE = 100;
const int NO_OF_STEPS = NO_OF_STEPS_TO_STORE;


namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	public: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Button^ ChinesePopulation;
	private: System::Windows::Forms::Button^ jeh;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Void Integrer_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ChinesePopulation_Click(System::Object^ sender, System::EventArgs^ e);
		bool Display2(double d2dArr[2][NO_OF_STEPS_TO_STORE]);
		bool Display2(double dXArr[NO_OF_STEPS_TO_STORE], double dYArr[NO_OF_STEPS_TO_STORE], int NoOfStepsToDisplay);
		bool Display2(double dXArr[NO_OF_STEPS_TO_STORE], double dYArr[NO_OF_STEPS_TO_STORE], double dYArr2[NO_OF_STEPS_TO_STORE], int NoOfStepsToDisplay);
	private: System::Void jeh_Click(System::Object^ sender, System::EventArgs^ e);
	

	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->ChinesePopulation = (gcnew System::Windows::Forms::Button());
			this->jeh = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1069, 39);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(81, 60);
			this->button1->TabIndex = 0;
			this->button1->Text = L"LOAD CHART";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// chart1
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(122, 12);
			this->chart1->Name = L"chart1";
			series3->BackGradientStyle = System::Windows::Forms::DataVisualization::Charting::GradientStyle::TopBottom;
			series3->BorderColor = System::Drawing::Color::Maroon;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series3->Legend = L"Legend1";
			series3->Name = L"Age";
			series3->YValuesPerPoint = 4;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series4->Legend = L"Legend1";
			series4->Name = L"Score";
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(941, 534);
			this->chart1->TabIndex = 1;
			this->chart1->Text = L"Population";
			this->chart1->Click += gcnew System::EventHandler(this, &Form1::chart1_Click);
			// 
			// ChinesePopulation
			// 
			this->ChinesePopulation->Location = System::Drawing::Point(1069, 131);
			this->ChinesePopulation->Name = L"ChinesePopulation";
			this->ChinesePopulation->Size = System::Drawing::Size(75, 23);
			this->ChinesePopulation->TabIndex = 2;
			this->ChinesePopulation->Text = L"ChinesePopulation";
			this->ChinesePopulation->UseVisualStyleBackColor = true;
			this->ChinesePopulation->Click += gcnew System::EventHandler(this, &Form1::ChinesePopulation_Click);
			// 
			// jeh
			// 
			this->jeh->Location = System::Drawing::Point(1069, 185);
			this->jeh->Name = L"jeh";
			this->jeh->Size = System::Drawing::Size(75, 23);
			this->jeh->TabIndex = 3;
			this->jeh->Text = L"jeh";
			this->jeh->UseVisualStyleBackColor = true;
			this->jeh->Click += gcnew System::EventHandler(this, &Form1::jeh_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1197, 562);
			this->Controls->Add(this->jeh);
			this->Controls->Add(this->ChinesePopulation);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		Button^ buttN = safe_cast<Button^>(sender);
		String^ s = buttN->Text;
		//if (buttN->Text == "AV") buttN->Text = "PÅ";
		//else buttN->Text = "AV";
		int ti = 5;

		//Load chart
		float Age[2][5] = { { 0.4, 0.8, 1.2, 1.6, 2.0 }, {3.2,5.5,6.9,5.7,4.3} };
		/*int lenA = sizeof(Age);
		int lenB = sizeof(Age[0]);
		int lenC = sizeof(Age[0][0]);
		int lenD = sizeof(float);
		int len = sizeof(Age[1][1]);*/

		for (int i = 0; i < 4; i++) {
			this->chart1->Series["Age"]->Points->AddXY(Age[0][i], Age[1][i]);
		}
		/*this->chart1->Series["Age"]->Points->AddXY(0.25,25.2);
		this->chart1->Series["Age"]->Points->AddXY(1, 35);
		this->chart1->Series["Age"]->Points->AddXY(1.9, 40);

		this->chart1->Series["Score"]->Points->AddXY(0.1, 25.2);
		this->chart1->Series["Score"]->Points->AddXY(0.8, 35);
		this->chart1->Series["Score"]->Points->AddXY(1.6, 40);*/

	}

	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

};
};
