#pragma once
#include "FrmInstructions.h"
#include "FrmLvl1.h"
#include "FrmLvl2.h"

namespace TFG1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmMainMenu
	/// </summary>
	public ref class FrmMainMenu : public System::Windows::Forms::Form
	{
	private:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	public:
		FrmMainMenu(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmMainMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BtnInstructions;
	protected:
	private: System::Windows::Forms::Button^ BtnLvl1;
	private: System::Windows::Forms::Button^ BtnLvl2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmMainMenu::typeid));
			this->BtnInstructions = (gcnew System::Windows::Forms::Button());
			this->BtnLvl1 = (gcnew System::Windows::Forms::Button());
			this->BtnLvl2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// BtnInstructions
			// 
			this->BtnInstructions->Location = System::Drawing::Point(819, 484);
			this->BtnInstructions->Name = L"BtnInstructions";
			this->BtnInstructions->Size = System::Drawing::Size(226, 62);
			this->BtnInstructions->TabIndex = 0;
			this->BtnInstructions->Text = L"Instrucciones";
			this->BtnInstructions->UseVisualStyleBackColor = true;
			this->BtnInstructions->Click += gcnew System::EventHandler(this, &FrmMainMenu::BtnInstructions_Click);
			// 
			// BtnLvl1
			// 
			this->BtnLvl1->Location = System::Drawing::Point(819, 423);
			this->BtnLvl1->Name = L"BtnLvl1";
			this->BtnLvl1->Size = System::Drawing::Size(110, 55);
			this->BtnLvl1->TabIndex = 1;
			this->BtnLvl1->Text = L"Facil";
			this->BtnLvl1->UseVisualStyleBackColor = true;
			this->BtnLvl1->Click += gcnew System::EventHandler(this, &FrmMainMenu::BtnLvl1_Click);
			// 
			// BtnLvl2
			// 
			this->BtnLvl2->Location = System::Drawing::Point(935, 423);
			this->BtnLvl2->Name = L"BtnLvl2";
			this->BtnLvl2->Size = System::Drawing::Size(110, 55);
			this->BtnLvl2->TabIndex = 2;
			this->BtnLvl2->Text = L"Extremo";
			this->BtnLvl2->UseVisualStyleBackColor = true;
			this->BtnLvl2->Click += gcnew System::EventHandler(this, &FrmMainMenu::BtnLvl2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1259, 657);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// FrmMainMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1260, 659);
			this->Controls->Add(this->BtnLvl2);
			this->Controls->Add(this->BtnLvl1);
			this->Controls->Add(this->BtnInstructions);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"FrmMainMenu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FrmMainMenu";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void BtnInstructions_Click(System::Object^ sender, System::EventArgs^ e) {
		FrmInstructions^ instrucc = gcnew FrmInstructions();
		instrucc->ShowDialog();
	}
private: System::Void BtnLvl1_Click(System::Object^ sender, System::EventArgs^ e) {
	FrmLvl1^ lvl1 = gcnew FrmLvl1();
	lvl1->ShowDialog();
}
private: System::Void BtnLvl2_Click(System::Object^ sender, System::EventArgs^ e) {
	FrmLvl2^ lvl2 = gcnew FrmLvl2();
	lvl2->ShowDialog();
}
};
}
