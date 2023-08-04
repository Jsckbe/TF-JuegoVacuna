#pragma once
#include "Controller.h"
#include "FrmWin.h"
#include "FrmLose.h"

namespace TFG1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmLvl2
	/// </summary>
	public ref class FrmLvl2 : public System::Windows::Forms::Form
	{
	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmap
		Bitmap^ spritePlayer;
		Bitmap^ spriteEnemy;
		Bitmap^ spritePatient;
		Bitmap^ spriteDoctor;
		Bitmap^ spriteNurse;
		Bitmap^ spriteVaccine;
		Bitmap^ background;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblHp;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblPoints;
	private: System::Windows::Forms::Timer^ timerEnemies;

		   Controller* controller;


	public:
		FrmLvl2(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);

			spritePlayer = gcnew Bitmap("player.png");
			spriteEnemy = gcnew Bitmap("enemy.png");
			spritePatient = gcnew Bitmap("patient.png");
			spriteDoctor = gcnew Bitmap("doctor.png");
			spriteNurse = gcnew Bitmap("nurse.png");
			spriteVaccine = gcnew Bitmap("vaccine.png");
			background = gcnew Bitmap("background_02.jpg");

			controller = new Controller(spritePlayer, spriteEnemy, spritePatient);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmLvl2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timerMain;
	private: System::Windows::Forms::Timer^ timerPatients;
	protected:

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timerMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerPatients = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblHp = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblPoints = (gcnew System::Windows::Forms::Label());
			this->timerEnemies = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timerMain
			// 
			this->timerMain->Enabled = true;
			this->timerMain->Tick += gcnew System::EventHandler(this, &FrmLvl2::timerMain_Tick);
			// 
			// timerPatients
			// 
			this->timerPatients->Enabled = true;
			this->timerPatients->Interval = 1000;
			this->timerPatients->Tick += gcnew System::EventHandler(this, &FrmLvl2::timerPatients_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1158, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Vidas";
			// 
			// lblHp
			// 
			this->lblHp->AutoSize = true;
			this->lblHp->Location = System::Drawing::Point(1220, 25);
			this->lblHp->Name = L"lblHp";
			this->lblHp->Size = System::Drawing::Size(14, 16);
			this->lblHp->TabIndex = 1;
			this->lblHp->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1030, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Puntos";
			// 
			// lblPoints
			// 
			this->lblPoints->AutoSize = true;
			this->lblPoints->Location = System::Drawing::Point(1084, 25);
			this->lblPoints->Name = L"lblPoints";
			this->lblPoints->Size = System::Drawing::Size(14, 16);
			this->lblPoints->TabIndex = 3;
			this->lblPoints->Text = L"0";
			// 
			// timerEnemies
			// 
			this->timerEnemies->Enabled = true;
			this->timerEnemies->Interval = 5000;
			this->timerEnemies->Tick += gcnew System::EventHandler(this, &FrmLvl2::timerEnemies_Tick);
			// 
			// FrmLvl2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1306, 592);
			this->Controls->Add(this->lblPoints);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblHp);
			this->Controls->Add(this->label1);
			this->Name = L"FrmLvl2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FrmLvl2";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmLvl2::FrmLvl2_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmLvl2::FrmLvl2_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timerMain_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::WhiteSmoke);
		controller->collision(buffer->Graphics);
		controller->moveEverything(buffer->Graphics);
		buffer->Graphics->DrawImage(background, 0, 0, this->Width, this->Height);
		lblHp->Text = Convert::ToString(controller->getPlayer()->getHp());
		lblPoints->Text = Convert::ToString(controller->getPoints());
		controller->drawEverything(buffer->Graphics, spritePlayer, spriteDoctor, spriteNurse, spriteEnemy, spritePatient, spriteVaccine);
		buffer->Render(g);

		if (controller->getPlayer()->getHp() <= 0) {
			this->timerMain->Enabled = false;
			FrmLose^ frmlose = gcnew FrmLose();
			frmlose->ShowDialog();
			this->Close();
		}
	}
	private: System::Void FrmLvl2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::W: controller->getPlayer()->move(buffer->Graphics, 'W'); break;
		case Keys::A: controller->getPlayer()->move(buffer->Graphics, 'A'); break;
		case Keys::S: controller->getPlayer()->move(buffer->Graphics, 'S'); break;
		case Keys::D: controller->getPlayer()->move(buffer->Graphics, 'D'); break;
		case Keys::E:
			Vaccine* vac = new Vaccine(spriteVaccine->Width / 2, spriteVaccine->Height / 2, controller->getPlayer()->getX(), controller->getPlayer()->getY(), controller->getPlayer()->getDirection());
			controller->addVaccine(vac);
			break;
		}
	}
private: System::Void FrmLvl2_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	controller->getPlayer()->still();
}
private: System::Void timerPatients_Tick(System::Object^ sender, System::EventArgs^ e) {
	Patient* p = new Patient(spritePatient->Width / 4, spritePatient->Height / 4);
	controller->addPatient(p);
}
private: System::Void timerEnemies_Tick(System::Object^ sender, System::EventArgs^ e) {
	Enemy* ene = new Enemy(spriteEnemy->Width / 4, spriteEnemy->Height / 4, 2);
	controller->addEnemies(ene);
}
};
}
