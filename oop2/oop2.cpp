#include <iostream>
#include <string>
using namespace std;

class Patient {
protected:
	string Fullname;
public:
	Patient() {
		printf("Patient()\n");
		Fullname = "Nick Rainfield";
	}

	Patient(string Fullname) {
		printf("Patient(string Fullname)\n");
		this->Fullname = Fullname;
	}

	Patient(const Patient& p) {
		printf("Patient(const Patient &p)\n");
		Fullname = p.Fullname;
	}

	~Patient() {
		cout << "Fullname of the patient: " << Fullname << endl;
		printf("~Patient()\n");
	}
	string Name() {
		return Fullname;
	}
	void Rename(string NewName);
};

void Patient::Rename(string NewName) {
	Fullname = NewName;
}

class Diagnoses : public Patient {
protected:
	string Diagnosis;
public:
	Diagnoses() :Patient() {
		printf("Diagnoses()\n");

		Fullname = "Nick Rainfield";
		Diagnosis = "Nothing";
	}

	Diagnoses(string Fullname, string Diagnosis) :Patient(Fullname) {
		printf("Diagnoses(string Diagnosis)\n");
		this->Diagnosis = Diagnosis;
	}

	Diagnoses(const Diagnoses& p) {
		printf("Patient(const Diagnoses &p)\n");
		Diagnosis = p.Diagnosis;
		Fullname = p.Fullname;
	}

	~Diagnoses() {
		cout << "Diagnosis of the patient: " << Diagnosis << endl;
		printf("~Diagnoses()\n");
	}
	string DiagnosesAdd() {
		return Diagnosis;
	}
	void DiagnosesChange(string NewDiagnosis);
};

void Diagnoses::DiagnosesChange(string NewDiagnosis) {
	Diagnosis = NewDiagnosis;
}

class Ward {
private:
	Patient* p1;
	Patient* p2;
	Patient* p3;
public:
	Ward() {
		cout << "----Hospital ward----" << endl;
		p1 = new Patient();
		p2 = new Patient();
		p3 = new Patient();
	}

	Ward(string name1, string name2, string name3) {
		cout << "----Hospital ward----" << endl;
		p1 = new Patient(name1);
		p2 = new Patient(name2);
		p3 = new Patient(name3);
	}

	Ward(const Ward& pWard) {
		cout << "----Hospital ward----" << endl;
		p1 = new Patient(*(pWard.p1));
		p2 = new Patient(*(pWard.p2));
		p3 = new Patient(*(pWard.p3));
	}

	~Ward() {
		cout << "end -Hospital ward-" << endl;
		delete p1;
		delete p2;
		delete p3;
	}
};

void main() {
	setlocale(LC_ALL, "rus");
	cout << "Creating and Deleting a Class Object(Patient):" << endl;
	{
		cout << "Without parameters:" << endl;
		Patient p1;
		cout << "With parameters:" << endl;
		Patient p2("Louise Frank");
		cout << "Copy previous:" << endl;
		Patient p3(p2);
		cout << "Rename the second patient to Andre Glovatti" << endl;
		p2.Rename("Andre Glovatti");
		cout << "Their remove" << endl;
		cout << endl << endl;
	}

	cout << "Creating and Destroying a Derived Class(Diagnoses):" << endl;
	{
		cout << "Without parameters:" << endl;
		Diagnoses* p1 = new Diagnoses();
		cout << "With parameters:" << endl;
		Diagnoses* p2 = new Diagnoses("Vlad Grigoryev", "Tourette's disease");
		cout << "Copy previous:" << endl;
		Diagnoses* p3 = new Diagnoses(*p2);
		cout << "Change the diagnosis of the second patient to the diagnosis of the third:" << endl;
		p1->DiagnosesChange("pneumonia");
		cout << "Their remove" << endl;
		delete p1;
		delete p2;
		delete p3;
		cout  << endl << endl;
	}

	cout << "Creating and Destroying a Derived Class(Patient) as (Diagnosis):" << endl;
	{
		Patient* p = new Diagnoses();
		delete p;
	}
	cout << "Creating and Deleting an Object of the Ward Class(Больничная палата):" << endl;
	{
		cout << "Without parameters:" << endl;
		Ward* pWard1 = new Ward();
		cout << "With parameters:" << endl;
		Ward* pWard2 = new Ward("Louise Frank", "Andre Glovatti", "Vlad Grigoryev");
		cout << "Copy previous:" << endl;
		Ward* pWard3 = new Ward(*pWard2);
		cout << "Their remove" << endl;
		delete pWard1;
		delete pWard2;
		delete pWard3;
	}
}