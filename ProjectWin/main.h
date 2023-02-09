#pragma once
#include "HomeWork1_menu.h"
#include "Balls.h"

using namespace System;
using namespace System::Windows::Forms;

namespace ProjectWin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	

	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class main : public System::Windows::Forms::Form
	{
	public:
		main(void)
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
		~main()
		{
			if (components)
			{
				delete components;
			}
		}

	public: System::Windows::Forms::Button^ HW1;
	public: System::Windows::Forms::Button^ HW4;
	public: System::Windows::Forms::Button^ HW3;
	public: System::Windows::Forms::Button^ HW2;
	public: System::Windows::Forms::Button^ HW5;
	public: System::Windows::Forms::Button^ balls1;
	public: System::Windows::Forms::Button^ task_database;
	public: System::Windows::Forms::Button^ settings;
	public: System::Windows::Forms::Button^ loan;
	public: System::Windows::Forms::Button^ loan2;
	public: System::Windows::Forms::Button^ filter;
	public: System::Windows::Forms::Button^ copying_file;
	public: System::Windows::Forms::Button^ sorting_letters;
	public: System::Windows::Forms::Button^ pyatnashki;
	private: System::Windows::Forms::GroupBox^ groupBox_HW;
	private: System::Windows::Forms::GroupBox^ groupBox_another;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::GroupBox^ groupBox_HW1;
	private: System::Windows::Forms::Button^ back;
	private: System::Windows::Forms::Label^ label;
	private: System::Windows::Forms::Button^ apply;
	private: System::Windows::Forms::GroupBox^ groupBox_balls;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label_allpermut;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox_cntball;
	private: System::Windows::Forms::Label^ label_right;
	private: System::Windows::Forms::GroupBox^ groupBox_settings;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::GroupBox^ groupBox_HW2;
	private: System::Windows::Forms::GroupBox^ groupBox_HW3;
	public: System::Windows::Forms::Button^ cone;
	public: System::Windows::Forms::Button^ branching;
	public: System::Windows::Forms::Button^ sequence;
	public: System::Windows::Forms::Button^ function;
	private: System::Windows::Forms::CheckBox^ checkBox_light;
	private: System::Windows::Forms::CheckBox^ checkBox_dark;
	private: System::Windows::Forms::GroupBox^ groupBox_HW4;
	public: System::Windows::Forms::Button^ button_number_system;
	public: System::Windows::Forms::Button^ button_matrix;
	public: System::Windows::Forms::Button^ button_random_num;
	public: System::Windows::Forms::Button^ button_recognizer;
	public: System::Windows::Forms::Button^ button_sin;
	public: System::Windows::Forms::Button^ button_glory;
	public: System::Windows::Forms::Button^ button_geometry;
	public: System::Windows::Forms::Button^ button_number_sign;
	public: System::Windows::Forms::Button^ button_file_4;
	public: System::Windows::Forms::Button^ tabulation;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>

		void InitializeComponent(void)
		{
			System::Windows::Forms::Button^ exit;
			System::Windows::Forms::Button^ calculate;
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(main::typeid));
			this->groupBox_HW = (gcnew System::Windows::Forms::GroupBox());
			this->HW1 = (gcnew System::Windows::Forms::Button());
			this->HW2 = (gcnew System::Windows::Forms::Button());
			this->HW3 = (gcnew System::Windows::Forms::Button());
			this->HW4 = (gcnew System::Windows::Forms::Button());
			this->HW5 = (gcnew System::Windows::Forms::Button());
			this->groupBox_another = (gcnew System::Windows::Forms::GroupBox());
			this->balls1 = (gcnew System::Windows::Forms::Button());
			this->task_database = (gcnew System::Windows::Forms::Button());
			this->pyatnashki = (gcnew System::Windows::Forms::Button());
			this->groupBox_HW1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->groupBox_HW2 = (gcnew System::Windows::Forms::GroupBox());
			this->tabulation = (gcnew System::Windows::Forms::Button());
			this->sequence = (gcnew System::Windows::Forms::Button());
			this->function = (gcnew System::Windows::Forms::Button());
			this->branching = (gcnew System::Windows::Forms::Button());
			this->cone = (gcnew System::Windows::Forms::Button());
			this->groupBox_HW3 = (gcnew System::Windows::Forms::GroupBox());
			this->sorting_letters = (gcnew System::Windows::Forms::Button());
			this->filter = (gcnew System::Windows::Forms::Button());
			this->copying_file = (gcnew System::Windows::Forms::Button());
			this->loan2 = (gcnew System::Windows::Forms::Button());
			this->loan = (gcnew System::Windows::Forms::Button());
			this->groupBox_settings = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_dark = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_light = (gcnew System::Windows::Forms::CheckBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->apply = (gcnew System::Windows::Forms::Button());
			this->groupBox_balls = (gcnew System::Windows::Forms::GroupBox());
			this->label_right = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label_allpermut = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_cntball = (gcnew System::Windows::Forms::TextBox());
			this->settings = (gcnew System::Windows::Forms::Button());
			this->back = (gcnew System::Windows::Forms::Button());
			this->groupBox_HW4 = (gcnew System::Windows::Forms::GroupBox());
			this->button_number_system = (gcnew System::Windows::Forms::Button());
			this->button_matrix = (gcnew System::Windows::Forms::Button());
			this->button_random_num = (gcnew System::Windows::Forms::Button());
			this->button_recognizer = (gcnew System::Windows::Forms::Button());
			this->button_sin = (gcnew System::Windows::Forms::Button());
			this->button_glory = (gcnew System::Windows::Forms::Button());
			this->button_geometry = (gcnew System::Windows::Forms::Button());
			this->button_number_sign = (gcnew System::Windows::Forms::Button());
			this->button_file_4 = (gcnew System::Windows::Forms::Button());
			exit = (gcnew System::Windows::Forms::Button());
			calculate = (gcnew System::Windows::Forms::Button());
			this->groupBox_HW->SuspendLayout();
			this->groupBox_another->SuspendLayout();
			this->groupBox_HW1->SuspendLayout();
			this->groupBox_HW2->SuspendLayout();
			this->groupBox_HW3->SuspendLayout();
			this->groupBox_settings->SuspendLayout();
			this->groupBox_balls->SuspendLayout();
			this->groupBox_HW4->SuspendLayout();
			this->SuspendLayout();
			// 
			// exit
			// 
			exit->BackColor = System::Drawing::Color::Transparent;
			exit->Cursor = System::Windows::Forms::Cursors::Hand;
			exit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			exit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			exit->Location = System::Drawing::Point(18, 368);
			exit->Name = L"exit";
			exit->Size = System::Drawing::Size(164, 69);
			exit->TabIndex = 11;
			exit->TabStop = false;
			exit->Text = L"Выход";
			exit->UseVisualStyleBackColor = false;
			exit->Click += gcnew System::EventHandler(this, &main::exit_Click);
			// 
			// calculate
			// 
			calculate->BackColor = System::Drawing::Color::Transparent;
			calculate->Cursor = System::Windows::Forms::Cursors::Hand;
			calculate->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			calculate->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			calculate->Location = System::Drawing::Point(6, 234);
			calculate->Name = L"calculate";
			calculate->Size = System::Drawing::Size(164, 69);
			calculate->TabIndex = 15;
			calculate->TabStop = false;
			calculate->Text = L"Рассчитать";
			calculate->UseVisualStyleBackColor = false;
			calculate->Click += gcnew System::EventHandler(this, &main::calculate_Click);
			// 
			// groupBox_HW
			// 
			this->groupBox_HW->AutoSize = true;
			this->groupBox_HW->BackColor = System::Drawing::Color::Transparent;
			this->groupBox_HW->Controls->Add(this->HW1);
			this->groupBox_HW->Controls->Add(this->HW2);
			this->groupBox_HW->Controls->Add(this->HW3);
			this->groupBox_HW->Controls->Add(this->HW4);
			this->groupBox_HW->Controls->Add(this->HW5);
			this->groupBox_HW->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox_HW->ForeColor = System::Drawing::Color::Red;
			this->groupBox_HW->Location = System::Drawing::Point(12, 12);
			this->groupBox_HW->Name = L"groupBox_HW";
			this->groupBox_HW->Size = System::Drawing::Size(516, 200);
			this->groupBox_HW->TabIndex = 9;
			this->groupBox_HW->TabStop = false;
			this->groupBox_HW->Text = L"Д/З";
			// 
			// HW1
			// 
			this->HW1->BackColor = System::Drawing::Color::Transparent;
			this->HW1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HW1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->HW1->Location = System::Drawing::Point(6, 28);
			this->HW1->Name = L"HW1";
			this->HW1->Size = System::Drawing::Size(164, 69);
			this->HW1->TabIndex = 0;
			this->HW1->TabStop = false;
			this->HW1->Text = L"Д/З 1";
			this->HW1->UseVisualStyleBackColor = false;
			this->HW1->Click += gcnew System::EventHandler(this, &main::HW1_Click);
			// 
			// HW2
			// 
			this->HW2->BackColor = System::Drawing::Color::Transparent;
			this->HW2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HW2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->HW2->Location = System::Drawing::Point(176, 28);
			this->HW2->Name = L"HW2";
			this->HW2->Size = System::Drawing::Size(164, 69);
			this->HW2->TabIndex = 1;
			this->HW2->TabStop = false;
			this->HW2->Text = L"Д/З 2";
			this->HW2->UseVisualStyleBackColor = false;
			this->HW2->Click += gcnew System::EventHandler(this, &main::HW2_Click);
			// 
			// HW3
			// 
			this->HW3->BackColor = System::Drawing::Color::Transparent;
			this->HW3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HW3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->HW3->Location = System::Drawing::Point(346, 28);
			this->HW3->Name = L"HW3";
			this->HW3->Size = System::Drawing::Size(164, 69);
			this->HW3->TabIndex = 2;
			this->HW3->TabStop = false;
			this->HW3->Text = L"Д/З 3";
			this->HW3->UseVisualStyleBackColor = false;
			this->HW3->Click += gcnew System::EventHandler(this, &main::HW3_Click);
			// 
			// HW4
			// 
			this->HW4->BackColor = System::Drawing::Color::Transparent;
			this->HW4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HW4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->HW4->Location = System::Drawing::Point(6, 103);
			this->HW4->Name = L"HW4";
			this->HW4->Size = System::Drawing::Size(164, 69);
			this->HW4->TabIndex = 3;
			this->HW4->TabStop = false;
			this->HW4->Text = L"Д/З 4";
			this->HW4->UseVisualStyleBackColor = false;
			this->HW4->Click += gcnew System::EventHandler(this, &main::HW4_Click);
			// 
			// HW5
			// 
			this->HW5->BackColor = System::Drawing::Color::Transparent;
			this->HW5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HW5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->HW5->Location = System::Drawing::Point(176, 103);
			this->HW5->Name = L"HW5";
			this->HW5->Size = System::Drawing::Size(164, 69);
			this->HW5->TabIndex = 4;
			this->HW5->TabStop = false;
			this->HW5->Text = L"Д/З 5";
			this->HW5->UseVisualStyleBackColor = false;
			// 
			// groupBox_another
			// 
			this->groupBox_another->AutoSize = true;
			this->groupBox_another->Controls->Add(this->balls1);
			this->groupBox_another->Controls->Add(this->task_database);
			this->groupBox_another->Controls->Add(this->pyatnashki);
			this->groupBox_another->ForeColor = System::Drawing::Color::Red;
			this->groupBox_another->Location = System::Drawing::Point(12, 218);
			this->groupBox_another->Name = L"groupBox_another";
			this->groupBox_another->Size = System::Drawing::Size(516, 125);
			this->groupBox_another->TabIndex = 10;
			this->groupBox_another->TabStop = false;
			this->groupBox_another->Text = L"Другое";
			// 
			// balls1
			// 
			this->balls1->BackColor = System::Drawing::Color::Transparent;
			this->balls1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->balls1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->balls1->Location = System::Drawing::Point(6, 28);
			this->balls1->Name = L"balls1";
			this->balls1->Size = System::Drawing::Size(164, 69);
			this->balls1->TabIndex = 5;
			this->balls1->TabStop = false;
			this->balls1->Text = L"Шарики";
			this->balls1->UseVisualStyleBackColor = false;
			this->balls1->Click += gcnew System::EventHandler(this, &main::balls1_Click);
			// 
			// task_database
			// 
			this->task_database->BackColor = System::Drawing::Color::Transparent;
			this->task_database->Cursor = System::Windows::Forms::Cursors::Hand;
			this->task_database->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->task_database->Location = System::Drawing::Point(176, 28);
			this->task_database->Name = L"task_database";
			this->task_database->Size = System::Drawing::Size(164, 69);
			this->task_database->TabIndex = 6;
			this->task_database->Text = L"База заданий";
			this->task_database->UseVisualStyleBackColor = false;
			// 
			// pyatnashki
			// 
			this->pyatnashki->BackColor = System::Drawing::Color::Transparent;
			this->pyatnashki->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pyatnashki->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->pyatnashki->Location = System::Drawing::Point(346, 28);
			this->pyatnashki->Name = L"pyatnashki";
			this->pyatnashki->Size = System::Drawing::Size(164, 69);
			this->pyatnashki->TabIndex = 8;
			this->pyatnashki->TabStop = false;
			this->pyatnashki->Text = L"Пятнашки";
			this->pyatnashki->UseVisualStyleBackColor = false;
			// 
			// groupBox_HW1
			// 
			this->groupBox_HW1->AutoSize = true;
			this->groupBox_HW1->Controls->Add(this->button1);
			this->groupBox_HW1->Controls->Add(this->button2);
			this->groupBox_HW1->Controls->Add(this->button3);
			this->groupBox_HW1->Controls->Add(this->button4);
			this->groupBox_HW1->Controls->Add(this->button5);
			this->groupBox_HW1->ForeColor = System::Drawing::Color::Red;
			this->groupBox_HW1->Location = System::Drawing::Point(12, 12);
			this->groupBox_HW1->Name = L"groupBox_HW1";
			this->groupBox_HW1->Size = System::Drawing::Size(516, 200);
			this->groupBox_HW1->TabIndex = 14;
			this->groupBox_HW1->TabStop = false;
			this->groupBox_HW1->Text = L"Д/З 1 - Задания";
			this->groupBox_HW1->Visible = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Location = System::Drawing::Point(176, 103);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(164, 69);
			this->button1->TabIndex = 17;
			this->button1->Text = L"Лампа со шторой";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Location = System::Drawing::Point(6, 103);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(164, 69);
			this->button2->TabIndex = 16;
			this->button2->Text = L"Ещё уравнение";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Transparent;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Location = System::Drawing::Point(346, 28);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(164, 69);
			this->button3->TabIndex = 15;
			this->button3->Text = L"Уравнение";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Transparent;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Location = System::Drawing::Point(176, 28);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(164, 69);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Арифметика";
			this->button4->UseVisualStyleBackColor = false;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Transparent;
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Location = System::Drawing::Point(6, 28);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(164, 69);
			this->button5->TabIndex = 13;
			this->button5->Text = L"Имя";
			this->button5->UseVisualStyleBackColor = false;
			// 
			// groupBox_HW2
			// 
			this->groupBox_HW2->AutoSize = true;
			this->groupBox_HW2->BackColor = System::Drawing::Color::Transparent;
			this->groupBox_HW2->Controls->Add(this->tabulation);
			this->groupBox_HW2->Controls->Add(this->sequence);
			this->groupBox_HW2->Controls->Add(this->function);
			this->groupBox_HW2->Controls->Add(this->branching);
			this->groupBox_HW2->Controls->Add(this->cone);
			this->groupBox_HW2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox_HW2->ForeColor = System::Drawing::Color::Red;
			this->groupBox_HW2->Location = System::Drawing::Point(12, 12);
			this->groupBox_HW2->Name = L"groupBox_HW2";
			this->groupBox_HW2->Size = System::Drawing::Size(516, 200);
			this->groupBox_HW2->TabIndex = 0;
			this->groupBox_HW2->TabStop = false;
			this->groupBox_HW2->Text = L"Д/З 2 - Задания";
			this->groupBox_HW2->Visible = false;
			// 
			// tabulation
			// 
			this->tabulation->BackColor = System::Drawing::Color::Transparent;
			this->tabulation->Cursor = System::Windows::Forms::Cursors::Hand;
			this->tabulation->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->tabulation->Location = System::Drawing::Point(176, 103);
			this->tabulation->Name = L"tabulation";
			this->tabulation->Size = System::Drawing::Size(164, 69);
			this->tabulation->TabIndex = 8;
			this->tabulation->TabStop = false;
			this->tabulation->Text = L"Табуляция";
			this->tabulation->UseVisualStyleBackColor = false;
			// 
			// sequence
			// 
			this->sequence->BackColor = System::Drawing::Color::Transparent;
			this->sequence->Cursor = System::Windows::Forms::Cursors::Hand;
			this->sequence->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->sequence->Location = System::Drawing::Point(6, 103);
			this->sequence->Name = L"sequence";
			this->sequence->Size = System::Drawing::Size(164, 69);
			this->sequence->TabIndex = 7;
			this->sequence->TabStop = false;
			this->sequence->Text = L"Порядок";
			this->sequence->UseVisualStyleBackColor = false;
			// 
			// function
			// 
			this->function->BackColor = System::Drawing::Color::Transparent;
			this->function->Cursor = System::Windows::Forms::Cursors::Hand;
			this->function->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->function->Location = System::Drawing::Point(346, 28);
			this->function->Name = L"function";
			this->function->Size = System::Drawing::Size(164, 69);
			this->function->TabIndex = 6;
			this->function->TabStop = false;
			this->function->Text = L"Функция";
			this->function->UseVisualStyleBackColor = false;
			// 
			// branching
			// 
			this->branching->BackColor = System::Drawing::Color::Transparent;
			this->branching->Cursor = System::Windows::Forms::Cursors::Hand;
			this->branching->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->branching->Location = System::Drawing::Point(176, 28);
			this->branching->Name = L"branching";
			this->branching->Size = System::Drawing::Size(164, 69);
			this->branching->TabIndex = 5;
			this->branching->TabStop = false;
			this->branching->Text = L"Разветвление";
			this->branching->UseVisualStyleBackColor = false;
			// 
			// cone
			// 
			this->cone->BackColor = System::Drawing::Color::Transparent;
			this->cone->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cone->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->cone->Location = System::Drawing::Point(6, 28);
			this->cone->Name = L"cone";
			this->cone->Size = System::Drawing::Size(164, 69);
			this->cone->TabIndex = 4;
			this->cone->TabStop = false;
			this->cone->Text = L"Конус";
			this->cone->UseVisualStyleBackColor = false;
			// 
			// groupBox_HW3
			// 
			this->groupBox_HW3->AutoSize = true;
			this->groupBox_HW3->BackColor = System::Drawing::Color::Transparent;
			this->groupBox_HW3->Controls->Add(this->sorting_letters);
			this->groupBox_HW3->Controls->Add(this->filter);
			this->groupBox_HW3->Controls->Add(this->copying_file);
			this->groupBox_HW3->Controls->Add(this->loan2);
			this->groupBox_HW3->Controls->Add(this->loan);
			this->groupBox_HW3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox_HW3->ForeColor = System::Drawing::Color::Red;
			this->groupBox_HW3->Location = System::Drawing::Point(12, 12);
			this->groupBox_HW3->Name = L"groupBox_HW3";
			this->groupBox_HW3->Size = System::Drawing::Size(516, 200);
			this->groupBox_HW3->TabIndex = 0;
			this->groupBox_HW3->TabStop = false;
			this->groupBox_HW3->Text = L"Д/З 3 - Задания";
			this->groupBox_HW3->Visible = false;
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
			// groupBox_settings
			// 
			this->groupBox_settings->Controls->Add(this->checkBox_dark);
			this->groupBox_settings->Controls->Add(this->checkBox_light);
			this->groupBox_settings->Controls->Add(this->label);
			this->groupBox_settings->Controls->Add(this->apply);
			this->groupBox_settings->ForeColor = System::Drawing::Color::Red;
			this->groupBox_settings->Location = System::Drawing::Point(12, 12);
			this->groupBox_settings->Name = L"groupBox_settings";
			this->groupBox_settings->Size = System::Drawing::Size(516, 187);
			this->groupBox_settings->TabIndex = 1;
			this->groupBox_settings->TabStop = false;
			this->groupBox_settings->Text = L"Настройки";
			this->groupBox_settings->Visible = false;
			// 
			// checkBox_dark
			// 
			this->checkBox_dark->BackColor = System::Drawing::Color::Transparent;
			this->checkBox_dark->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->checkBox_dark->Checked = true;
			this->checkBox_dark->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox_dark->Cursor = System::Windows::Forms::Cursors::Hand;
			this->checkBox_dark->Location = System::Drawing::Point(176, 75);
			this->checkBox_dark->Name = L"checkBox_dark";
			this->checkBox_dark->Size = System::Drawing::Size(108, 28);
			this->checkBox_dark->TabIndex = 3;
			this->checkBox_dark->Text = L"Тёмная";
			this->checkBox_dark->UseVisualStyleBackColor = false;
			this->checkBox_dark->CheckedChanged += gcnew System::EventHandler(this, &main::checkBox_dark_CheckedChanged);
			// 
			// checkBox_light
			// 
			this->checkBox_light->BackColor = System::Drawing::Color::Transparent;
			this->checkBox_light->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->checkBox_light->Cursor = System::Windows::Forms::Cursors::Hand;
			this->checkBox_light->Location = System::Drawing::Point(176, 49);
			this->checkBox_light->Name = L"checkBox_light";
			this->checkBox_light->Size = System::Drawing::Size(108, 28);
			this->checkBox_light->TabIndex = 1;
			this->checkBox_light->Text = L"Светлая";
			this->checkBox_light->UseVisualStyleBackColor = false;
			this->checkBox_light->CheckedChanged += gcnew System::EventHandler(this, &main::checkBox_light_CheckedChanged);
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Location = System::Drawing::Point(6, 48);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(168, 24);
			this->label->TabIndex = 2;
			this->label->Text = L"Тема программы:";
			// 
			// apply
			// 
			this->apply->BackColor = System::Drawing::Color::Transparent;
			this->apply->Cursor = System::Windows::Forms::Cursors::Hand;
			this->apply->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->apply->Location = System::Drawing::Point(54, 149);
			this->apply->Name = L"apply";
			this->apply->Size = System::Drawing::Size(120, 32);
			this->apply->TabIndex = 1;
			this->apply->Text = L"Применить";
			this->apply->UseVisualStyleBackColor = false;
			this->apply->Click += gcnew System::EventHandler(this, &main::apply_Click);
			// 
			// groupBox_balls
			// 
			this->groupBox_balls->AutoSize = true;
			this->groupBox_balls->BackColor = System::Drawing::Color::Transparent;
			this->groupBox_balls->Controls->Add(calculate);
			this->groupBox_balls->Controls->Add(this->label_right);
			this->groupBox_balls->Controls->Add(this->label3);
			this->groupBox_balls->Controls->Add(this->label_allpermut);
			this->groupBox_balls->Controls->Add(this->label2);
			this->groupBox_balls->Controls->Add(this->label1);
			this->groupBox_balls->Controls->Add(this->textBox_cntball);
			this->groupBox_balls->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox_balls->ForeColor = System::Drawing::Color::Red;
			this->groupBox_balls->Location = System::Drawing::Point(12, 12);
			this->groupBox_balls->Name = L"groupBox_balls";
			this->groupBox_balls->Size = System::Drawing::Size(516, 331);
			this->groupBox_balls->TabIndex = 0;
			this->groupBox_balls->TabStop = false;
			this->groupBox_balls->Text = L"Шарики";
			this->groupBox_balls->Visible = false;
			// 
			// label_right
			// 
			this->label_right->AutoSize = true;
			this->label_right->Location = System::Drawing::Point(339, 155);
			this->label_right->Name = L"label_right";
			this->label_right->Size = System::Drawing::Size(0, 24);
			this->label_right->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 155);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(327, 24);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Количество нужных перестановок:";
			// 
			// label_allpermut
			// 
			this->label_allpermut->AutoSize = true;
			this->label_allpermut->Location = System::Drawing::Point(329, 93);
			this->label_allpermut->Name = L"label_allpermut";
			this->label_allpermut->Size = System::Drawing::Size(0, 24);
			this->label_allpermut->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 93);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(317, 24);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Общее количество перестановок:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(284, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Введите количество шариков:";
			// 
			// textBox_cntball
			// 
			this->textBox_cntball->BackColor = System::Drawing::Color::Black;
			this->textBox_cntball->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_cntball->ForeColor = System::Drawing::Color::Red;
			this->textBox_cntball->Location = System::Drawing::Point(296, 31);
			this->textBox_cntball->MaxLength = 25;
			this->textBox_cntball->Name = L"textBox_cntball";
			this->textBox_cntball->Size = System::Drawing::Size(130, 29);
			this->textBox_cntball->TabIndex = 0;
			// 
			// settings
			// 
			this->settings->BackColor = System::Drawing::Color::Transparent;
			this->settings->Cursor = System::Windows::Forms::Cursors::Hand;
			this->settings->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->settings->Location = System::Drawing::Point(358, 368);
			this->settings->Name = L"settings";
			this->settings->Size = System::Drawing::Size(164, 69);
			this->settings->TabIndex = 7;
			this->settings->TabStop = false;
			this->settings->Text = L"Настройки";
			this->settings->UseVisualStyleBackColor = false;
			this->settings->Click += gcnew System::EventHandler(this, &main::settings_Click);
			// 
			// back
			// 
			this->back->BackColor = System::Drawing::Color::Transparent;
			this->back->Cursor = System::Windows::Forms::Cursors::Hand;
			this->back->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->back->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->back->Location = System::Drawing::Point(188, 368);
			this->back->Name = L"back";
			this->back->Size = System::Drawing::Size(164, 69);
			this->back->TabIndex = 12;
			this->back->TabStop = false;
			this->back->Text = L"Назад";
			this->back->UseVisualStyleBackColor = false;
			this->back->Visible = false;
			this->back->Click += gcnew System::EventHandler(this, &main::back_Click);
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
			this->groupBox_HW4->Visible = false;
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
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(540, 457);
			this->Controls->Add(this->groupBox_HW);
			this->Controls->Add(this->groupBox_settings);
			this->Controls->Add(this->back);
			this->Controls->Add(exit);
			this->Controls->Add(this->groupBox_another);
			this->Controls->Add(this->settings);
			this->Controls->Add(this->groupBox_HW1);
			this->Controls->Add(this->groupBox_HW2);
			this->Controls->Add(this->groupBox_HW3);
			this->Controls->Add(this->groupBox_HW4);
			this->Controls->Add(this->groupBox_balls);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ForeColor = System::Drawing::Color::Red;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(6);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Процедурное программирование";
			this->Load += gcnew System::EventHandler(this, &main::MyForm1_Load);
			this->groupBox_HW->ResumeLayout(false);
			this->groupBox_another->ResumeLayout(false);
			this->groupBox_HW1->ResumeLayout(false);
			this->groupBox_HW2->ResumeLayout(false);
			this->groupBox_HW3->ResumeLayout(false);
			this->groupBox_settings->ResumeLayout(false);
			this->groupBox_settings->PerformLayout();
			this->groupBox_balls->ResumeLayout(false);
			this->groupBox_balls->PerformLayout();
			this->groupBox_HW4->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void exit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void HW1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void back_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void settings_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void apply_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void HW2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void HW3_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void balls1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkBox_light_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkBox_dark_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void calculate_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void HW4_Click(System::Object^ sender, System::EventArgs^ e);

};
}
