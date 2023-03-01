#pragma once
#include "main.h"

namespace ProjectWin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для HomeWork1_menu
	/// </summary>
	public ref class HomeWork1_menu : public System::Windows::Forms::Form
	{
	public:
		HomeWork1_menu(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~HomeWork1_menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox_HW4_number_system;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox_num_for_convert;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::CheckBox^ checkBox_from_another;
	private: System::Windows::Forms::CheckBox^ checkBox_from_16;
	private: System::Windows::Forms::CheckBox^ checkBox_from_10;
	private: System::Windows::Forms::CheckBox^ checkBox_from_8;
	private: System::Windows::Forms::CheckBox^ checkBox_from_2;
	private: System::Windows::Forms::TextBox^ textBox_to_another;
	private: System::Windows::Forms::TextBox^ textBox_from_another;
	private: System::Windows::Forms::Label^ label_result;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::CheckBox^ checkBox_to_another;

	private: System::Windows::Forms::CheckBox^ checkBox_to_16;

	private: System::Windows::Forms::CheckBox^ checkBox_to_10;

	private: System::Windows::Forms::CheckBox^ checkBox_to_8;

	private: System::Windows::Forms::CheckBox^ checkBox_to_2;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(HomeWork1_menu::typeid));
			this->groupBox_HW4_number_system = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_from_another = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_from_16 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_from_10 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_from_8 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_from_2 = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox_num_for_convert = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox_to_another = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_to_16 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_to_10 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_to_8 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_to_2 = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label_result = (gcnew System::Windows::Forms::Label());
			this->textBox_from_another = (gcnew System::Windows::Forms::TextBox());
			this->textBox_to_another = (gcnew System::Windows::Forms::TextBox());
			this->groupBox_HW4_number_system->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox_HW4_number_system
			// 
			this->groupBox_HW4_number_system->Controls->Add(this->textBox_to_another);
			this->groupBox_HW4_number_system->Controls->Add(this->textBox_from_another);
			this->groupBox_HW4_number_system->Controls->Add(this->label_result);
			this->groupBox_HW4_number_system->Controls->Add(this->label5);
			this->groupBox_HW4_number_system->Controls->Add(this->label4);
			this->groupBox_HW4_number_system->Controls->Add(this->checkBox_to_another);
			this->groupBox_HW4_number_system->Controls->Add(this->checkBox_to_16);
			this->groupBox_HW4_number_system->Controls->Add(this->checkBox_to_10);
			this->groupBox_HW4_number_system->Controls->Add(this->checkBox_to_8);
			this->groupBox_HW4_number_system->Controls->Add(this->checkBox_to_2);
			this->groupBox_HW4_number_system->Controls->Add(this->checkBox_from_another);
			this->groupBox_HW4_number_system->Controls->Add(this->checkBox_from_16);
			this->groupBox_HW4_number_system->Controls->Add(this->checkBox_from_10);
			this->groupBox_HW4_number_system->Controls->Add(this->checkBox_from_8);
			this->groupBox_HW4_number_system->Controls->Add(this->checkBox_from_2);
			this->groupBox_HW4_number_system->Controls->Add(this->label3);
			this->groupBox_HW4_number_system->Controls->Add(this->label2);
			this->groupBox_HW4_number_system->Controls->Add(this->textBox_num_for_convert);
			this->groupBox_HW4_number_system->Controls->Add(this->label1);
			this->groupBox_HW4_number_system->ForeColor = System::Drawing::Color::Red;
			this->groupBox_HW4_number_system->Location = System::Drawing::Point(12, 12);
			this->groupBox_HW4_number_system->Name = L"groupBox_HW4_number_system";
			this->groupBox_HW4_number_system->Size = System::Drawing::Size(516, 331);
			this->groupBox_HW4_number_system->TabIndex = 0;
			this->groupBox_HW4_number_system->TabStop = false;
			this->groupBox_HW4_number_system->Text = L"Д/З 4 - Задания - Системы счисления";
			// 
			// checkBox_from_another
			// 
			this->checkBox_from_another->AutoSize = true;
			this->checkBox_from_another->Location = System::Drawing::Point(45, 193);
			this->checkBox_from_another->Name = L"checkBox_from_another";
			this->checkBox_from_another->Size = System::Drawing::Size(15, 14);
			this->checkBox_from_another->TabIndex = 8;
			this->checkBox_from_another->UseVisualStyleBackColor = true;
			// 
			// checkBox_from_16
			// 
			this->checkBox_from_16->AutoSize = true;
			this->checkBox_from_16->Location = System::Drawing::Point(45, 150);
			this->checkBox_from_16->Name = L"checkBox_from_16";
			this->checkBox_from_16->Size = System::Drawing::Size(49, 28);
			this->checkBox_from_16->TabIndex = 7;
			this->checkBox_from_16->Text = L"16";
			this->checkBox_from_16->UseVisualStyleBackColor = true;
			// 
			// checkBox_from_10
			// 
			this->checkBox_from_10->AutoSize = true;
			this->checkBox_from_10->Location = System::Drawing::Point(45, 116);
			this->checkBox_from_10->Name = L"checkBox_from_10";
			this->checkBox_from_10->Size = System::Drawing::Size(49, 28);
			this->checkBox_from_10->TabIndex = 6;
			this->checkBox_from_10->Text = L"10";
			this->checkBox_from_10->UseVisualStyleBackColor = true;
			// 
			// checkBox_from_8
			// 
			this->checkBox_from_8->AutoSize = true;
			this->checkBox_from_8->Location = System::Drawing::Point(45, 82);
			this->checkBox_from_8->Name = L"checkBox_from_8";
			this->checkBox_from_8->Size = System::Drawing::Size(44, 28);
			this->checkBox_from_8->TabIndex = 5;
			this->checkBox_from_8->Text = L" 8";
			this->checkBox_from_8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->checkBox_from_8->UseVisualStyleBackColor = true;
			// 
			// checkBox_from_2
			// 
			this->checkBox_from_2->AutoSize = true;
			this->checkBox_from_2->Location = System::Drawing::Point(45, 48);
			this->checkBox_from_2->Name = L"checkBox_from_2";
			this->checkBox_from_2->Size = System::Drawing::Size(44, 28);
			this->checkBox_from_2->TabIndex = 4;
			this->checkBox_from_2->Text = L" 2";
			this->checkBox_from_2->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(100, 48);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(21, 24);
			this->label3->TabIndex = 3;
			this->label3->Text = L"в";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 49);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 24);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Из";
			// 
			// textBox_num_for_convert
			// 
			this->textBox_num_for_convert->BackColor = System::Drawing::Color::Black;
			this->textBox_num_for_convert->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox_num_for_convert->ForeColor = System::Drawing::Color::Red;
			this->textBox_num_for_convert->Location = System::Drawing::Point(221, 27);
			this->textBox_num_for_convert->Name = L"textBox_num_for_convert";
			this->textBox_num_for_convert->Size = System::Drawing::Size(289, 22);
			this->textBox_num_for_convert->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(209, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Число для преревода:";
			// 
			// checkBox_to_another
			// 
			this->checkBox_to_another->AutoSize = true;
			this->checkBox_to_another->Location = System::Drawing::Point(127, 193);
			this->checkBox_to_another->Name = L"checkBox_to_another";
			this->checkBox_to_another->Size = System::Drawing::Size(15, 14);
			this->checkBox_to_another->TabIndex = 13;
			this->checkBox_to_another->UseVisualStyleBackColor = true;
			// 
			// checkBox_to_16
			// 
			this->checkBox_to_16->AutoSize = true;
			this->checkBox_to_16->Location = System::Drawing::Point(127, 150);
			this->checkBox_to_16->Name = L"checkBox_to_16";
			this->checkBox_to_16->Size = System::Drawing::Size(49, 28);
			this->checkBox_to_16->TabIndex = 12;
			this->checkBox_to_16->Text = L"16";
			this->checkBox_to_16->UseVisualStyleBackColor = true;
			// 
			// checkBox_to_10
			// 
			this->checkBox_to_10->AutoSize = true;
			this->checkBox_to_10->Location = System::Drawing::Point(127, 116);
			this->checkBox_to_10->Name = L"checkBox_to_10";
			this->checkBox_to_10->Size = System::Drawing::Size(49, 28);
			this->checkBox_to_10->TabIndex = 11;
			this->checkBox_to_10->Text = L"10";
			this->checkBox_to_10->UseVisualStyleBackColor = true;
			// 
			// checkBox_to_8
			// 
			this->checkBox_to_8->AutoSize = true;
			this->checkBox_to_8->Location = System::Drawing::Point(127, 82);
			this->checkBox_to_8->Name = L"checkBox_to_8";
			this->checkBox_to_8->Size = System::Drawing::Size(44, 28);
			this->checkBox_to_8->TabIndex = 10;
			this->checkBox_to_8->Text = L" 8";
			this->checkBox_to_8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->checkBox_to_8->UseVisualStyleBackColor = true;
			// 
			// checkBox_to_2
			// 
			this->checkBox_to_2->AutoSize = true;
			this->checkBox_to_2->Location = System::Drawing::Point(127, 48);
			this->checkBox_to_2->Name = L"checkBox_to_2";
			this->checkBox_to_2->Size = System::Drawing::Size(44, 28);
			this->checkBox_to_2->TabIndex = 9;
			this->checkBox_to_2->Text = L" 2";
			this->checkBox_to_2->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(177, 48);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(188, 24);
			this->label4->TabIndex = 14;
			this->label4->Text = L"систему счисления.";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 255);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(201, 24);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Результат перевода:";
			// 
			// label_result
			// 
			this->label_result->AutoSize = true;
			this->label_result->Location = System::Drawing::Point(213, 255);
			this->label_result->Name = L"label_result";
			this->label_result->Size = System::Drawing::Size(0, 24);
			this->label_result->TabIndex = 16;
			// 
			// textBox_from_another
			// 
			this->textBox_from_another->BackColor = System::Drawing::Color::Black;
			this->textBox_from_another->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox_from_another->ForeColor = System::Drawing::Color::Red;
			this->textBox_from_another->Location = System::Drawing::Point(66, 187);
			this->textBox_from_another->Name = L"textBox_from_another";
			this->textBox_from_another->Size = System::Drawing::Size(23, 22);
			this->textBox_from_another->TabIndex = 17;
			// 
			// textBox_to_another
			// 
			this->textBox_to_another->BackColor = System::Drawing::Color::Black;
			this->textBox_to_another->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox_to_another->ForeColor = System::Drawing::Color::Red;
			this->textBox_to_another->Location = System::Drawing::Point(148, 187);
			this->textBox_to_another->Name = L"textBox_to_another";
			this->textBox_to_another->Size = System::Drawing::Size(23, 22);
			this->textBox_to_another->TabIndex = 18;
			// 
			// HomeWork1_menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(540, 457);
			this->Controls->Add(this->groupBox_HW4_number_system);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ForeColor = System::Drawing::Color::Red;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(6);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"HomeWork1_menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Процедурное программирование";
			this->groupBox_HW4_number_system->ResumeLayout(false);
			this->groupBox_HW4_number_system->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void back_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void task_name_Click(System::Object^ sender, System::EventArgs^ e);

};
}
