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
	private: System::Windows::Forms::GroupBox^ groupBox_HW4;
	protected:

	public: System::Windows::Forms::Button^ button_number_system;
	private:

	public: System::Windows::Forms::Button^ button_matrix;
	private:

	public: System::Windows::Forms::Button^ button_random_num;

	public: System::Windows::Forms::Button^ button_recognizer;

	public: System::Windows::Forms::Button^ button_sin;

	public: System::Windows::Forms::Button^ button_glory;

	public: System::Windows::Forms::Button^ button_geometry;

	public: System::Windows::Forms::Button^ button_number_sign;

	public: System::Windows::Forms::Button^ button_file_4;









	protected:







	public:

	public:

	public:






	private:

	private:
	protected:

	protected:

	protected:



	protected:




	protected:

	protected:

	protected:






	protected:

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
			this->groupBox_HW4 = (gcnew System::Windows::Forms::GroupBox());
			this->button_file_4 = (gcnew System::Windows::Forms::Button());
			this->button_number_sign = (gcnew System::Windows::Forms::Button());
			this->button_geometry = (gcnew System::Windows::Forms::Button());
			this->button_glory = (gcnew System::Windows::Forms::Button());
			this->button_sin = (gcnew System::Windows::Forms::Button());
			this->button_recognizer = (gcnew System::Windows::Forms::Button());
			this->button_random_num = (gcnew System::Windows::Forms::Button());
			this->button_matrix = (gcnew System::Windows::Forms::Button());
			this->button_number_system = (gcnew System::Windows::Forms::Button());
			this->groupBox_HW4->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox_HW4
			// 
			this->groupBox_HW4->AutoSize = true;
			this->groupBox_HW4->BackColor = System::Drawing::Color::Transparent;
			this->groupBox_HW4->Controls->Add(this->button_number_system);
			this->groupBox_HW4->Controls->Add(this->button_matrix);
			this->groupBox_HW4->Controls->Add(this->button_random_num);
			this->groupBox_HW4->Controls->Add(this->button_recognizer);
			this->groupBox_HW4->Controls->Add(this->button_sin);
			this->groupBox_HW4->Controls->Add(this->button_glory);
			this->groupBox_HW4->Controls->Add(this->button_geometry);
			this->groupBox_HW4->Controls->Add(this->button_number_sign);
			this->groupBox_HW4->Controls->Add(this->button_file_4);
			this->groupBox_HW4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox_HW4->ForeColor = System::Drawing::Color::Red;
			this->groupBox_HW4->Location = System::Drawing::Point(12, 12);
			this->groupBox_HW4->Name = L"groupBox_HW4";
			this->groupBox_HW4->Size = System::Drawing::Size(516, 275);
			this->groupBox_HW4->TabIndex = 0;
			this->groupBox_HW4->TabStop = false;
			this->groupBox_HW4->Text = L"Д/З 4 - Задания";
			// 
			// button_file_4
			// 
			this->button_file_4->BackColor = System::Drawing::Color::Transparent;
			this->button_file_4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_file_4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_file_4->Location = System::Drawing::Point(6, 28);
			this->button_file_4->Name = L"button_file_4";
			this->button_file_4->Size = System::Drawing::Size(164, 69);
			this->button_file_4->TabIndex = 5;
			this->button_file_4->TabStop = false;
			this->button_file_4->Text = L"Файл";
			this->button_file_4->UseVisualStyleBackColor = false;
			// 
			// button_number_sign
			// 
			this->button_number_sign->BackColor = System::Drawing::Color::Transparent;
			this->button_number_sign->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_number_sign->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_number_sign->Location = System::Drawing::Point(176, 28);
			this->button_number_sign->Name = L"button_number_sign";
			this->button_number_sign->Size = System::Drawing::Size(164, 69);
			this->button_number_sign->TabIndex = 6;
			this->button_number_sign->TabStop = false;
			this->button_number_sign->Text = L"Знак числа";
			this->button_number_sign->UseVisualStyleBackColor = false;
			// 
			// button_geometry
			// 
			this->button_geometry->BackColor = System::Drawing::Color::Transparent;
			this->button_geometry->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_geometry->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_geometry->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_geometry->Location = System::Drawing::Point(346, 28);
			this->button_geometry->Name = L"button_geometry";
			this->button_geometry->Size = System::Drawing::Size(164, 69);
			this->button_geometry->TabIndex = 7;
			this->button_geometry->TabStop = false;
			this->button_geometry->Text = L"Геометрические фигуры";
			this->button_geometry->UseVisualStyleBackColor = false;
			// 
			// button_glory
			// 
			this->button_glory->BackColor = System::Drawing::Color::Transparent;
			this->button_glory->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_glory->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_glory->Location = System::Drawing::Point(6, 103);
			this->button_glory->Name = L"button_glory";
			this->button_glory->Size = System::Drawing::Size(164, 69);
			this->button_glory->TabIndex = 8;
			this->button_glory->TabStop = false;
			this->button_glory->Text = L"Былая слава";
			this->button_glory->UseVisualStyleBackColor = false;
			// 
			// button_sin
			// 
			this->button_sin->BackColor = System::Drawing::Color::Transparent;
			this->button_sin->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_sin->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_sin->Location = System::Drawing::Point(176, 103);
			this->button_sin->Name = L"button_sin";
			this->button_sin->Size = System::Drawing::Size(164, 69);
			this->button_sin->TabIndex = 9;
			this->button_sin->TabStop = false;
			this->button_sin->Text = L"Синус";
			this->button_sin->UseVisualStyleBackColor = false;
			// 
			// button_recognizer
			// 
			this->button_recognizer->BackColor = System::Drawing::Color::Transparent;
			this->button_recognizer->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_recognizer->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_recognizer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_recognizer->Location = System::Drawing::Point(346, 103);
			this->button_recognizer->Name = L"button_recognizer";
			this->button_recognizer->Size = System::Drawing::Size(164, 69);
			this->button_recognizer->TabIndex = 10;
			this->button_recognizer->TabStop = false;
			this->button_recognizer->Text = L"Автоматный распознаватель";
			this->button_recognizer->UseVisualStyleBackColor = false;
			// 
			// button_random_num
			// 
			this->button_random_num->BackColor = System::Drawing::Color::Transparent;
			this->button_random_num->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_random_num->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_random_num->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_random_num->Location = System::Drawing::Point(6, 178);
			this->button_random_num->Name = L"button_random_num";
			this->button_random_num->Size = System::Drawing::Size(164, 69);
			this->button_random_num->TabIndex = 11;
			this->button_random_num->TabStop = false;
			this->button_random_num->Text = L"Генератор псевдослучайных чисел";
			this->button_random_num->UseVisualStyleBackColor = false;
			// 
			// button_matrix
			// 
			this->button_matrix->BackColor = System::Drawing::Color::Transparent;
			this->button_matrix->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_matrix->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_matrix->Location = System::Drawing::Point(176, 178);
			this->button_matrix->Name = L"button_matrix";
			this->button_matrix->Size = System::Drawing::Size(164, 69);
			this->button_matrix->TabIndex = 12;
			this->button_matrix->TabStop = false;
			this->button_matrix->Text = L"Умножение матриц";
			this->button_matrix->UseVisualStyleBackColor = false;
			// 
			// button_number_system
			// 
			this->button_number_system->BackColor = System::Drawing::Color::Transparent;
			this->button_number_system->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_number_system->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_number_system->Location = System::Drawing::Point(346, 178);
			this->button_number_system->Name = L"button_number_system";
			this->button_number_system->Size = System::Drawing::Size(164, 69);
			this->button_number_system->TabIndex = 13;
			this->button_number_system->TabStop = false;
			this->button_number_system->Text = L"Системы счисления";
			this->button_number_system->UseVisualStyleBackColor = false;
			// 
			// HomeWork1_menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(540, 457);
			this->Controls->Add(this->groupBox_HW4);
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
			this->groupBox_HW4->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void back_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void task_name_Click(System::Object^ sender, System::EventArgs^ e);


private: System::Void textBox_cntball_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
