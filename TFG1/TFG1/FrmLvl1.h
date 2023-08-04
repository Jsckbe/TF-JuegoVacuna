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
	/// Summary for FrmLvl1
	/// </summary>
	public ref class FrmLvl1 : public System::Windows::Forms::Form
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

		int contAllies;

	private: System::Windows::Forms::Timer^ timerMain;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblHp;

		   Controller* controller;
	public:
		FrmLvl1(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);

			//Bitmap
			spritePlayer = gcnew Bitmap("player.png");
			spriteEnemy = gcnew Bitmap("enemy.png");
			spritePatient = gcnew Bitmap("patient.png");
			spriteDoctor = gcnew Bitmap("doctor.png");
			spriteNurse = gcnew Bitmap("nurse.png");
			spriteVaccine = gcnew Bitmap("vaccine.png");
			background = gcnew Bitmap("background_01.jpg");

			//Controller
			controller = new Controller(spritePlayer, spriteEnemy, spritePatient);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmLvl1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblHp = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timerMain
			// 
			this->timerMain->Enabled = true;
			this->timerMain->Tick += gcnew System::EventHandler(this, &FrmLvl1::timerMain_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1086, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Vidas:";
			// 
			// lblHp
			// 
			this->lblHp->AutoSize = true;
			this->lblHp->Location = System::Drawing::Point(1137, 25);
			this->lblHp->Name = L"lblHp";
			this->lblHp->Size = System::Drawing::Size(10, 16);
			this->lblHp->TabIndex = 1;
			this->lblHp->Text = L".";
			// 
			// FrmLvl1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1267, 619);
			this->Controls->Add(this->lblHp);
			this->Controls->Add(this->label1);
			this->Name = L"FrmLvl1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FrmLvl1";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmLvl1::FrmLvl1_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmLvl1::FrmLvl1_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timerMain_Tick(System::Object^ sender, System::EventArgs^ e) {
		// Erase
		buffer->Graphics->Clear(Color::WhiteSmoke);
		// Collision
		controller->collision(buffer->Graphics);
		// Move
		controller->moveEverything(buffer->Graphics);
		// Draw
		buffer->Graphics->DrawImage(background, 0, 0, this->Width, this->Height);
		lblHp->Text = Convert::ToString(controller->getPlayer()->getHp());
		controller->drawEverything(buffer->Graphics, spritePlayer, spriteDoctor, spriteNurse, spriteEnemy, spritePatient, spriteVaccine);
		buffer->Render(g);

		if (controller->getNPatients() <= 0) {
			this->timerMain->Enabled = false;
			FrmWin^ frmwin = gcnew FrmWin();
			frmwin->ShowDialog();
			this->Close();
		}
		if (controller->getPlayer()->getHp() <= 0) {
			this->timerMain->Enabled = false;
			FrmLose^ frmlose = gcnew FrmLose();
			frmlose->ShowDialog();
			this->Close();
		}
	}
	private: System::Void FrmLvl1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::W: controller->getPlayer()->move(buffer->Graphics, 'W'); break;
		case Keys::A: controller->getPlayer()->move(buffer->Graphics, 'A'); break;
		case Keys::S: controller->getPlayer()->move(buffer->Graphics, 'S'); break;
		case Keys::D: controller->getPlayer()->move(buffer->Graphics, 'D'); break;
		case Keys::F: {
			int id = rand() % 2;
			if (contAllies < 4) {
				switch (id)
				{
				case 0: {
					Doctor* doc = new Doctor(spriteDoctor->Width / 4, spriteDoctor->Height / 4, rand() % 2);
					controller->addDoctor(doc); }
					break;
				case 1:
					Nurse * nur = new Nurse(spriteNurse->Width / 4, spriteNurse->Height / 4, rand() % 2);
					controller->addNurse(nur);
					break;
				}

			}
			if (contAllies <= 4);
			contAllies++;
		} break;
		case Keys::E:
			Vaccine* vac = new Vaccine(spriteVaccine->Width / 2, spriteVaccine->Height / 2, controller->getPlayer()->getX(), controller->getPlayer()->getY(), controller->getPlayer()->getDirection());
			controller->addVaccine(vac);
			break;
		}
	}
	private: System::Void FrmLvl1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		controller->getPlayer()->still();
	}
	};
}
