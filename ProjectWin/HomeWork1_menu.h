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
	private: System::Windows::Forms::GroupBox^ groupBox_HW2;
	public: System::Windows::Forms::Button^ loan;
	public: System::Windows::Forms::Button^ loan2;
	public: System::Windows::Forms::Button^ filter;
	public: System::Windows::Forms::Button^ copying_file;
	public: System::Windows::Forms::Button^ sorting_letters;






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
			this->groupBox_HW2 = (gcnew System::Windows::Forms::GroupBox());
			this->sorting_letters = (gcnew System::Windows::Forms::Button());
			this->filter = (gcnew System::Windows::Forms::Button());
			this->copying_file = (gcnew System::Windows::Forms::Button());
			this->loan2 = (gcnew System::Windows::Forms::Button());
			this->loan = (gcnew System::Windows::Forms::Button());
			this->groupBox_HW2->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox_HW2
			// 
			this->groupBox_HW2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox_HW2->AutoSize = true;
			this->groupBox_HW2->BackColor = System::Drawing::Color::Transparent;
			this->groupBox_HW2->Controls->Add(this->sorting_letters);
			this->groupBox_HW2->Controls->Add(this->filter);
			this->groupBox_HW2->Controls->Add(this->copying_file);
			this->groupBox_HW2->Controls->Add(this->loan2);
			this->groupBox_HW2->Controls->Add(this->loan);
			this->groupBox_HW2->ForeColor = System::Drawing::Color::Red;
			this->groupBox_HW2->Location = System::Drawing::Point(12, 12);
			this->groupBox_HW2->Name = L"groupBox_HW2";
			this->groupBox_HW2->Size = System::Drawing::Size(516, 200);
			this->groupBox_HW2->TabIndex = 0;
			this->groupBox_HW2->TabStop = false;
			this->groupBox_HW2->Text = L"Задания";
			// 
			// sorting_letters
			// 
			this->sorting_letters->BackColor = System::Drawing::Color::Transparent;
			this->sorting_letters->Cursor = System::Windows::Forms::Cursors::Hand;
			this->sorting_letters->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->sorting_letters->Location = System::Drawing::Point(176, 103);
			this->sorting_letters->Name = L"sorting_letters";
			this->sorting_letters->Size = System::Drawing::Size(164, 69);
			this->sorting_letters->TabIndex = 8;
			this->sorting_letters->TabStop = false;
			this->sorting_letters->Text = L"Сортировка букв";
			this->sorting_letters->UseVisualStyleBackColor = false;
			// 
			// filter
			// 
			this->filter->BackColor = System::Drawing::Color::Transparent;
			this->filter->Cursor = System::Windows::Forms::Cursors::Hand;
			this->filter->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->filter->Location = System::Drawing::Point(6, 103);
			this->filter->Name = L"filter";
			this->filter->Size = System::Drawing::Size(164, 69);
			this->filter->TabIndex = 7;
			this->filter->TabStop = false;
			this->filter->Text = L"Фильтр";
			this->filter->UseVisualStyleBackColor = false;
			// 
			// copying_file
			// 
			this->copying_file->BackColor = System::Drawing::Color::Transparent;
			this->copying_file->Cursor = System::Windows::Forms::Cursors::Hand;
			this->copying_file->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->copying_file->Location = System::Drawing::Point(346, 28);
			this->copying_file->Name = L"copying_file";
			this->copying_file->Size = System::Drawing::Size(164, 69);
			this->copying_file->TabIndex = 6;
			this->copying_file->TabStop = false;
			this->copying_file->Text = L"Копирование файла";
			this->copying_file->UseVisualStyleBackColor = false;
			// 
			// loan2
			// 
			this->loan2->BackColor = System::Drawing::Color::Transparent;
			this->loan2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->loan2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->loan2->Location = System::Drawing::Point(176, 28);
			this->loan2->Name = L"loan2";
			this->loan2->Size = System::Drawing::Size(164, 69);
			this->loan2->TabIndex = 5;
			this->loan2->TabStop = false;
			this->loan2->Text = L"Ссуда";
			this->loan2->UseVisualStyleBackColor = false;
			// 
			// loan
			// 
			this->loan->BackColor = System::Drawing::Color::Transparent;
			this->loan->Cursor = System::Windows::Forms::Cursors::Hand;
			this->loan->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->loan->Location = System::Drawing::Point(6, 28);
			this->loan->Name = L"loan";
			this->loan->Size = System::Drawing::Size(164, 69);
			this->loan->TabIndex = 4;
			this->loan->TabStop = false;
			this->loan->Text = L"Заём";
			this->loan->UseVisualStyleBackColor = false;
			// 
			// HomeWork1_menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(540, 457);
			this->Controls->Add(this->groupBox_HW2);
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
			this->groupBox_HW2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void back_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void task_name_Click(System::Object^ sender, System::EventArgs^ e);



};
}
