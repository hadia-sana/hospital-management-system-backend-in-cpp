#include <iostream>

using namespace std;
#include<string.h>
#include<cstring>
#include<stdlib.h>
#include<chrono>
#include<vector>
#include<thread>
#include<stdbool.h>
//----------------------------------------------functions------------------------------------------------------------------------
//----------------------------------------------classes--------------------------------------------------------------------------
class person{
protected:
    //string name;
    char firstname[8];

    int age;
    //string gender;
    char secondname[8];
    char gender[7];
public:
    person(const char* firstname1,const char* secondname2,int age,const char* gender1){

    strcpy(firstname,firstname1);
    strcpy(secondname,secondname2);
    strcpy(gender,gender1);
    this->age=age;
    }
    person(){
    cout<<endl<<"enter first name:";
    //getline(cin,name);
    cin>>firstname;
    cout<<endl<<"enter second name:";
    //getline(cin,name);                                    //default const
    cin>>secondname;
    cout<<endl<<"enter age:";
    cin>>age;
    cout<<endl<<"enter gender:";
    cin>>gender;


    }

    void show(){
//    cout<<endl<<"name:"<<firstname<<" "<<secondname;
//    cout<<endl<<"age:"<<age<<" years";
//    cout<<endl<<"gender:"<<gender;
cout<<endl<<"NAME:"<<firstname<<" "<<secondname<<"       AGE:"<<age<<"          GENDER:"<<gender<<"            ";

    }
//    string getfirstname(){
//    return firstname;
//    }
//     string getsecondname(){
//    return secondname;
//    }
    char* getfirstname(){
    return firstname;
    }
     char* getsecondname(){
    return secondname;
    }

};

                             //===================================***====================================
class staff:public person{
protected:
    //char role[14];
    char role[40];
    //string role
    int salary;
public:
    staff(const char* firstname,const char* secondname,int age,const char* gender,const char* role1,int salary):person(firstname,secondname,age,gender){
    strcpy(role,role1);
    this->salary=salary;                                      //para const
    }
//    staff(const char* firstname,const char* secondname,int age,const char* gender,const char* role1,int salary):person(firstname,secondname,age,gender){
//    strcpy(role,role1);
//    this->salary=salary;                                      //para const
//    }

    staff(){
    cout<<endl<<"enter role:";
    cin>>role;
    cout<<endl<<"enter salary:";                           //default const
    cin>>salary;
    }
    int getsalary(){
    return salary;
    }

    void show(){
    person::show();
    //cout<<endl<<"role:"<<role;
    cout<<"role:"<<role;

    }
//    string getrole(){
//return role;
//}
    char* getrole(){
return role;
}



};
                             //--------------------------------------------------------------------
    class bill{
    protected:
//      char name_b[30];
//        char disease_b[20];
//        char gender_b[12];
//        int age_b;

      int days;
   char discharge_date[18];
        int amount;
        float tax;
    public:


    void add_bill_info(){
//    cout<<endl<<"enter patient name:";
//    cin>>name_b;
//    cout<<endl<<"enter age:";
//    cin>>age_b;
//    cout<<endl<<"enter disease:";
//    cin>>disease_b;
//    cout<<endl<<"enter gender:";
//    cin>>gender_b;
   cout<<endl<<"enter discharge date:";
 cin>>discharge_date;
    cout<<endl<<"enter total days spent in hospital days:";
    cin>>days;
    cout<<endl<<"enter per day amount(depending upon room/bed):";
    cin>>amount;
    cout<<endl<<"enter tax:";
    cin>>tax;


    }

    float calculate_bill(){
        float amount_r=(days*amount)+tax;
        return amount_r;

    }
    void display_bill(){
        //cout<<endl<<"*********************************************************************BILL OF PATIENT*******************************************************************"<<endl;
//    cout<<endl<<" patient name:"<<name_b;
//
//    cout<<endl<<" age:"<<age_b;
//
//    cout<<endl<<" disease:"<<disease_b;
//
//    cout<<endl<<" gender:"<<gender_b;
//
//    cout<<endl<<" days:"<<days;

    cout<<endl<<"TOTAL amount:rs "<<this->calculate_bill();

    }




    };

class patient:public person{
protected:


    char disease[15];
    char bloodGroup[3];
    int roomNo;
    char dateofAdmit[25];
    bill patient_bill;


public:
    patient(const char* firstname,const char* secondname, const char* disease1,const char* bloodGroup1, const char* gender, int age, int roomNo, const char* dateofAdmit1):person(firstname,secondname,age,gender){

        strcpy(disease,disease1);
        strcpy(bloodGroup,bloodGroup1);              //para const
        strcpy(dateofAdmit,dateofAdmit1);
        this->roomNo=roomNo;



    }
    patient(){
    cout<<endl<<"enter disease:";
    cin>>disease;                                          //default const
    cout<<endl<<"enter bloodgroup:";
    cin>>bloodGroup;
    cout<<endl<<"enter room number:";
    cin>>roomNo;
    cout<<endl<<"enter date of admit:";
    cin>>dateofAdmit;

    }

    void show(){
    person::show();
//    cout<<endl<<"disease:"<<disease;
//    cout<<endl<<"blood group:"<<bloodGroup;
//    cout<<endl<<"room number:"<<roomNo;
//    cout<<endl<<"date of Admit:"<<dateofAdmit;
cout<<"        DISEASE:"<<disease<<"                  BLOOD GROUP:"<<bloodGroup<<"            ROOM NUMBER:"<<roomNo<<"              DATE OF ADMIT:"<<dateofAdmit;

    }
    void patient_bill_calculate(){
    patient_bill.add_bill_info();
    cout<<endl<<endl<<endl<<"*******************************$$$$$$$$$$$$$$$$$$$$$$$$$$$BILL OF PATIENT$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*******************************"<<endl<<endl;
    this->show();
    patient_bill.display_bill();
    }
//    void show_patient_bill_calculate(){
//    //cout<<endl<<endl<<endl<<"*******************************$$$$$$$$$$$$$$$$$$$$$$$$$$$BILL OF PATIENT$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*******************************"<<endl<<endl;
//    this->show();
//    patient_bill.display_bill();
//
//    }




};

//--------------------------------------------------------------record of hospital------------------------------------------------------
class birthrecord:public person{
protected:
    char date_of_birth[20];
public:
    /*birthrecord(){
        cout<<endl<<"enter date of birth:";
    cin>>date_of_birth;
    }*/
    birthrecord(const char*firstname,const char*secondname,const char*gender,int age,const char*date_of_birth1):person(firstname,secondname,age,gender){
    strcpy(date_of_birth,date_of_birth1);

    }
    void show(){
    //person::show();
    cout<<endl<<"name:"<<firstname<<" "<<secondname<<"            age:"<<age<<" days"<<"           gender:"<<gender<<"           date of birth:"<<date_of_birth;
//    cout<<endl<<"age:"<<age<<" days";
//    cout<<endl<<"gender:"<<gender;
//    cout<<endl<<"date of birth:"<<date_of_birth;
    }
    };
    class deathrecord:public person{
protected:
    char date_of_death[20];
    char disease[15];
public:
    deathrecord(){
        cout<<endl<<"enter date of death:";
    cin>>date_of_death;
    }
    deathrecord(const char*firstname,const char*secondname,const char*gender,int age,const char*date_of_death1,const char*disease1):person(firstname,secondname,age,gender){
    strcpy(date_of_death,date_of_death1);
    strcpy(disease,disease1);

    }
    void show(){
    person::show();
    cout<<endl<<"date of birth:"<<date_of_death;
    }
    };
                               //----------------------------------doctor------------------------------------------------//
class doctor:public staff{
protected:
    char id[10];
     //char specialization[15];
     char specialization[70];
     char phoneNo[13];

public:

doctor(const char* firstname,const char* secondname,int age,const char* gender,const char* role,int salary,const char* id1, const char* specialization1, const char* phoneNo1):staff( firstname,secondname, age, gender, role, salary){
                                               //para const
    strcpy(id,id1);
    strcpy(specialization,specialization1);
    strcpy(phoneNo,phoneNo1);
}
doctor(){
    cout<<endl<<"enter id :";
    cin>>id;
    cout<<endl<<"enter specialization:";                                  //default const
    cin>>specialization;
    cout<<endl<<" enter phoneNo:";
    cin>>phoneNo;

}

void show(){
staff::show();
cout<<        "id:"<<id<<"          specialization:"<<specialization<<"                                                     phone number:"<<phoneNo;
//cout<<endl<<"specialization:"<<specialization;
//cout<<endl<<"phone number:"<<phoneNo;
}
//string getrole(){
//return role;
//}
//string getspecialization(){
//return specialization;
//}
char* getspecialization(){
return specialization;
}



};
//-------------------------------online p===================
class online_patient:public person{
protected:
    string disease;
    doctor*doc[5];
public:
    online_patient(){
    cout<<endl<<"concern/disease:";
    cin.ignore();
    //cin>>disease;
    getline(cin,disease);

}
void add_doc(doctor*d[5]){
for(int i=0;i<5;i++){
    doc[i]=d[i];
    //doc[i]=d+i;

}
}
//-------------changing
void setdisease(string disease){
this->disease=disease;
}
    void recommended_doctor(){
        if(disease=="neurology"){
            cout<<endl<<"RECOMMENDED DOCTOR FOR YOU:"<<doc[0]->getfirstname();
            cout<<" "<<doc[0]->getsecondname();

            cout<<endl<<"specialization and qualification:"<<doc[0]->getspecialization();
            cout<<endl<<"timing:"<<doc[0]->getrole();

        }
        else if(disease=="oncology"){
            cout<<endl<<"RECOMMENDED DOCTOR FOR YOU:"<<doc[1]->getfirstname();
            cout<<" "<<doc[1]->getsecondname();

            cout<<endl<<"specialization and qualification:"<<doc[1]->getspecialization();
            cout<<endl<<"timing:"<<doc[1]->getrole();
        }
        else if(disease=="renal"||disease=="liver"||disease=="gastrointestine"){
            cout<<endl<<"RECOMMENDED DOCTOR FOR YOU:"<<doc[2]->getfirstname();
            cout<<" "<<doc[2]->getsecondname();

            cout<<endl<<"specialization and qualification:"<<doc[2]->getspecialization();
            cout<<endl<<"timing:"<<doc[2]->getrole();
        }
        else if(disease=="gynaecology"){
            cout<<endl<<"RECOMMENDED DOCTOR FOR YOU:"<<doc[3]->getfirstname();
            cout<<" "<<doc[3]->getsecondname();

            cout<<endl<<"specialization and qualification:"<<doc[3]->getspecialization();
            cout<<endl<<"timing:"<<doc[3]->getrole();
        }
        else if(disease=="cardiology"){
            cout<<endl<<"RECOMMENDED DOCTOR FOR YOU:"<<doc[4]->getfirstname();
            cout<<" "<<doc[4]->getsecondname();

            cout<<endl<<"specialization and qualification:"<<doc[4]->getspecialization();
            cout<<endl<<"timing:"<<doc[4]->getrole();
        }
        else{
            cout<<endl<<"not available";}}
            /*void recommended_doctor(){
        if(disease=="neurology"){
            cout<<endl<<doc[0]->getfirstname();
        }
        else if(disease=="oncology"){
            cout<<endl<<doc[1]->getfirstname();
        }
        else if(disease=="renal"){
            cout<<endl<<doc[2]->getfirstname();
        }
        else if(disease=="gynaecology"){
            cout<<endl<<doc[3]->getfirstname();
        }
        else if(disease=="liver and gastrointestine"){
            cout<<endl<<doc[4]->getfirstname();
        }
        else{
            cout<<endl<<"not available";}}*/


            };
            //======================================blood bank=================================================
            /*class blooddbank{
            protected:
                string blood_group[25];
                string blood_group_dynamic;
            public:
                void add_bloodgroup(){
                for(int i=0;i<3;i++){
                    blood_group[i]="A";
                }
                                for(int i=0;i<5;i++){
                    blood_group[i]="A+";
                }
                                for(int i=5;i<8;i++){
                    blood_group[i]="B";
                }
                                for(int i=8;i<10;i++){
                    blood_group[i]="B+";
                }
                                for(int i=10;i<13;i++){
                   blood_group[i]="AB";
                }


                                for(int i=13;i<16;i++){
                    blood_group[i]="O+";
                }
                                for(int i=16;i<20;i++){
                    blood_group[i]="O-";
                }

                                for(int i=20;i<25;i++){
                    blood_group[i]="A-";
                }}
                void show_blood_group(){
                for(int i=0;i<25;i++){
                    cout<<endl<<blood_group[i];
                }

                }



            };*/
            //============================blood bank system================================

class bloodunit{
protected:
    //char blood_type[2];
    char blood_type[4];
    string donor_id;
    //int count_donation;
    static int total_unit_count;
    string dateofBloodexpiry;
public:
    bloodunit(const char* blood_type1,string donor_id,string dateofBloodexpiry){
    //this->blood_type=blood_type;
    strcpy(blood_type,blood_type1);
    this->donor_id=donor_id;
    this->dateofBloodexpiry=dateofBloodexpiry;
    total_unit_count++;

    }
    bloodunit(){
        cout<<endl<<"enter blood type:";
        cin>>blood_type[2];
        cout<<endl<<"enter donor id:";
        cin>>donor_id;
        cout<<endl<<"enter date of expiry of unit:";
        cin>>dateofBloodexpiry;


    }
//    void set_bloodtype(){
//
//    }

    //void setblood_type
    void display_bloodunit(){
//    cout<<endl<<"blood type:";
//        cout<<blood_type;
//        cout<<endl<<"donor id:";
//        cout<<donor_id;
//        cout<<endl<<"date of expiry of unit:";
//        cout<<dateofBloodexpiry;
cout<<endl<<"BLOOD TYPE:"<<blood_type<<"        DONOR ID:"<<donor_id<<"              DATE OF EXPIRY OF UNIT:"<<dateofBloodexpiry;

    }
    char* get_blood_type(){
    return blood_type;
    }


};
 int bloodunit::total_unit_count=0;


class donor:public person{
    protected:
        string type;
        int count_donation;
    string donor_id;
    bloodunit*unit;
    public:
        donor(const char*firstname,const char*secondname,int age,const char*gender,string type,int count_donation,string donor_id):person(firstname,secondname,age,gender)
        {
            this->type=type;
            this->donor_id=donor_id;
            this->count_donation=count_donation;
        }
        donor():person(){
        cout<<endl<<"enter type regular or irregular:";
        cin>>type;
        cout<<endl<<"enter donor id:";
        cin>>donor_id;

        }

        void setcount_donation(int count_donation){
        this->count_donation=count_donation;
        }
        void addbloodunit(bloodunit*unit){
        this->unit=unit;
        }
        void show(){
            person::show();
            cout<<"         Type:"<<type<<"                   Donor id:"<<donor_id<<"                    No_of_times donated"<<count_donation;
//        cout<<type;
//        cout<<endl<<"donor id:";
//        cout<<donor_id;
//        cout<<endl<<"no_of_times donated"<<count_donation;


        }





};
class bloodinventory{
    private:
bloodunit*blood_group[25];
//bloodunit*b_group_dynamic
donor*blood_donors[7];
public:
    void add_units(){
     for(int i=0;i<3;i++){
                    blood_group[i]=new bloodunit("A","ali ahmad","02-02-2023");
                }
                                for(int i=0;i<5;i++){
                                       blood_group[i]=new bloodunit("O-","ali ahmad","02-02-2023");
                }
                                for(int i=5;i<8;i++){
                                       blood_group[i]=new bloodunit("B+","omer ahmad","02-02-2023");
                                for(int i=8;i<10;i++){
                                       blood_group[i]=new bloodunit("A+","saim ali","02-02-2023");
                }
                                for(int i=10;i<13;i++){
                                       blood_group[i]=new bloodunit("A-","ahsan khan","02-02-2023");
                }


                                for(int i=13;i<16;i++){
                                       blood_group[i]=new bloodunit("AB","ali naeem","02-02-2023");
                }
                                for(int i=16;i<20;i++){
                                       blood_group[i]=new bloodunit("B-","omer naik","02-02-2023");
                }

                                for(int i=20;i<25;i++){
                                       blood_group[i]=new bloodunit("O+","anas ali","02-02-2023");

    }
    }}
    void blood_search(){
    cout<<endl<<endl<<"ENTER THE BLOOD TYPE REQUIRED:";
//    cin.ignore();
//    char searchb[4];
//    cin.getline(searchb,4);
string searchb;
cin>>searchb;
    bool check_flag=false;
    for(int i=0;i<25;i++){
        if(blood_group[i]->get_blood_type() == searchb){
            cout<<endl<<"YES! IT IS AVAILABLE"<<endl;
            blood_group[i]->display_bloodunit();
            check_flag=true;
            break;
        }

    }
    if(check_flag==false){
        cout<<endl<<"SORRY! NOT AVAILABLE";
    }


    }
    void show_add_units(){
     for(int i=0;i<3;i++){
             cout<<endl<<endl;
                    blood_group[i]->display_bloodunit();
                }
                                for(int i=0;i<5;i++){
                                        cout<<endl<<endl;
                    blood_group[i]->display_bloodunit();
                }
                                for(int i=5;i<8;i++){
                                         cout<<endl<<endl;
                    blood_group[i]->display_bloodunit();
                }
                                for(int i=8;i<10;i++){
                                         cout<<endl<<endl;
                    blood_group[i]->display_bloodunit();
                }
                                for(int i=10;i<13;i++){
                                         cout<<endl<<endl;
                   blood_group[i]->display_bloodunit();
                }


                                for(int i=13;i<16;i++){
                                         cout<<endl<<endl;
                    blood_group[i]->display_bloodunit();
                }
                                for(int i=16;i<20;i++){
                                         cout<<endl<<endl;
                    blood_group[i]->display_bloodunit();
                }

                                for(int i=20;i<25;i++){
                                         cout<<endl<<endl;
                    blood_group[i]->display_bloodunit();}


    }
    void add_regular_donor(){
        blood_donors[0]=new donor("ali","ahmad",25,"male","regular",5,"al-shifa-d01");
        blood_donors[1]=new donor("ali","ahmad",25,"male","regular",5,"al-shifa-d01");
        blood_donors[2]=new donor("ali","ahmad",25,"male","regular",5,"al-shifa-d01");
        blood_donors[3]=new donor("ali","ahmad",25,"male","regular",5,"al-shifa-d01");
        blood_donors[4]=new donor("ali","ahmad",25,"male","regular",5,"al-shifa-d01");
        blood_donors[5]=new donor("ali","ahmad",25,"male","regular",5,"al-shifa-d01");
        blood_donors[6]=new donor("ali","ahmad",25,"male","regular",5,"al-shifa-d01");


    }
    void show_regular_donor(){
    for(int i=0;i<7;i++){
             cout<<endl<<endl;
        blood_donors[i]->show();
    }
    }


};

//=========================================================================================================================================
class hospital{
private:
    string name;
    string address;
   //bloodinventory inv;

    doctor*reg_doc[5];             //array of regular doctor
    doctor*special_doc[5];
    patient*hosp_patients[12]; //array of specialist doctor
    staff*nurse[8];
    staff*add_nurse[8];
    staff*additional[5];

    doctor*added_doctor[5];
    patient*added_patient[7];
    birthrecord birth_rec[5];
    deathrecord death_rec[5];





public:
    /*hospital(string name,string address):birth_rec("ali","ahmad","male",2,"20-8-12"){

    this->name=name;
    this->address=address;
    }*/
    hospital(string name,string address):birth_rec{birthrecord("ali","ahmad","male",2,"20-8-12"),birthrecord("ali","ahmad","male",2,"20-8-12"),birthrecord("ali","ahmad","male",2,"20-8-12"),birthrecord("ali","ahmad","male",2,"20-8-12"),birthrecord("ali","ahmad","male",2,"20-8-12")},

    death_rec{deathrecord("ali","imran","male",95,"25-55-2","malaria"),deathrecord("ali","imran","male",95,"25-55-2","malaria"),deathrecord("ali","imran","male",95,"25-55-2","malaria"),deathrecord("ali","imran","male",95,"25-55-2","malaria"),deathrecord("ali","imran","male",95,"25-55-2","malaria")}



    {
    this->name=name;
    this->address=address;

    }
    //==================================nurse and additionals==================================================================================
   void reg_nurse(){
   nurse[0]=new staff("amna","ilyas",25,"female","nurse",22000);
    nurse[1]=new staff("amna","ilyas",25,"female","nurse",22000);
     nurse[2]=new staff("amna","ilyas",25,"female","nurse",22000);
      nurse[3]=new staff("amna","ilyas",25,"female","nurse",22000);
       nurse[4]=new staff("amna","ilyas",25,"female","nurse",22000);
        nurse[5]=new staff("amna","ilyas",25,"female","nurse",22000);
         nurse[6]=new staff("amna","ilyas",25,"female","nurse",22000);
          nurse[7]=new staff("amna","ilyas",25,"female","nurse",22000);
   }
   void reg_additional(){
   additional[0]=new staff("eina","faar",22,"female","sweeper floor 1",15000);
   additional[1]=new staff("eina","faar",22,"female","sweeper floor 1",15000);
   additional[2]=new staff("eina","faar",22,"female","sweeper floor 1",15000);
   additional[3]=new staff("eina","faar",22,"female","sweeper floor 1",15000);
   additional[4]=new staff("eina","faar",22,"female","sweeper floor 1",15000);
   }
   void show_reg_additional(){
   for(int i=0;i<5;i++){
    additional[0]->show();
   }
   }
   void reg_nurse(int size){
   for(int i=0;i<size;i++){
    cout<<endl<<"add "<<i+1<<" nurse:-"<<endl;
    add_nurse[i]=new staff();
   }

   }
   void display_reg_nurse(){
   for(int i=0;i<8;i++){
    nurse[i]->show();
   }

   }
    void display_reg_nurse(int size){
   for(int i=0;i<size;i++){
        cout<<endl;
    add_nurse[i]->show();
   }

   }
//=======================================================================================================
    void add_added_doctor(int size){
    for(int i=0;i<size;i++){
            cout<<endl<<"enter"<<i+1<<"doctor:-"<<endl;
        added_doctor[i]=new doctor();
    }

    }
    void show_added_doctor(int size){
        cout<<endl<<endl<<"=================================NEWLY REGISTERED DOCTORS================================"<<endl;
    for(int i=0;i<size;i++){
            cout<<endl<<endl;

        added_doctor[i]->show();
    }

    }
    void add_added_patient(int size){
    for(int i=0;i<size;i++){
            cout<<endl<<"enter"<<i+1<<"patient:-"<<endl;
        added_patient[i]=new patient();
    }

    }
    void show_added_patient(int size){
        cout<<endl<<endl<<"=====================================NEWLY ADMITTED PATIENTS============================="<<endl;
    for(int i=0;i<size;i++){
            cout<<endl<<endl;

        added_patient[i]->show();
    }

    }




    void addreg_doc(){
reg_doc[0]=new doctor("Ali","Ahmad",26,"Male","1 to 7pm shift",40000,"alshifa12","mbbs,fcps","03090000024");
reg_doc[1]=new doctor("Ali","Ahmad",26,"Male","1 to 7pm shift",40000,"alshifa12","mbbs,fcps","03090000024");
reg_doc[2]=new doctor("Ali","Ahmad",26,"Male","1 to 7pm shift",40000,"alshifa12","mbbs,fcps","03090000024");
reg_doc[3]=new doctor("Ali","Ahmad",26,"Male","1 to 7pm shift",40000,"alshifa12","mbbs,fcps","03090000024");
reg_doc[4]=new doctor("Ali","Ahmad",26,"Male","1 to 7pm shift",40000,"alshifa12","mbbs,fcps","03090000024");}
void addspecial_doc(){
special_doc[0]=new doctor("Anas","Ahmad",26,"Male","2pm to 3pm from monday to wednesday",40000,"alshifa12","mbbs,fcps,specialization in neurology","03094580024");
special_doc[1]=new doctor("amir","Ahmad",26,"Male","2pm to 3pm from tuesday to thrusday",40000,"alshifa12","mbbs,fcps,specialization in oncology","03090088824");
special_doc[2]=new doctor("omer","Ahmad",26,"Male","2pm to 3pm from monday to wednesday",40000,"alshifa12","mbbs,fcps,specialization in liver,kidney,gastrointology","03090000024");
special_doc[3]=new doctor("Amna","Ahmad",26,"Male","2pm to 3pm from friday and saturday",40000,"alshifa12","mbbs,fcps,specialization in gynaecology","03090044424");
special_doc[4]=new doctor("afia","Ahmad",26,"Male","2pm to 3pm from monday to wednesday",40000,"alshifa12","mbbs,fcps,specialization in cardiology","03587698524");
}
void showreg_doc(){
for(int i=0;i<5;i++){
        cout<<endl<<endl;

    reg_doc[i]->show();
}}
void showspecial_doc(){
for(int i=0;i<5;i++){
        cout<<endl<<endl;

    special_doc[i]->show();
    }
}
void hospDocShow(){
cout<<endl<<"====================================REGULAR DOCTORS OF HOSPITAL====================================";
    this->showreg_doc();
cout<<endl<<"====================================specialized DOCTORS OF HOSPITAL====================================";
     this->showspecial_doc();
    }
//----------------------------------------------patient thing------------------------------------------------------
     void addreg_patient(){
     hosp_patients[0]=new patient("amna","dar","malaria","B+","female",25,7,"3-8-2023");
    hosp_patients[1]=new patient("amna","dar","malaria","B+","female",25,7,"3-8-2023");

    hosp_patients[2]=new patient("amna","dar","malaria","B+","female",25,7,"3-8-2023");
     hosp_patients[3]=new patient("amna","dar","malaria","B+","female",25,7,"3-8-2023");
     hosp_patients[4]=new patient("amna","dar","malaria","B+","female",25,7,"3-8-2023");
     hosp_patients[5]=new patient("amna","dar","malaria","B+","female",25,7,"3-8-2023");
     hosp_patients[6]=new patient("amna","dar","malaria","B+","female",25,7,"3-8-2023");
     hosp_patients[7]=new patient("amna","dar","malaria","B+","female",25,7,"3-8-2023");
     hosp_patients[8]=new patient("amna","dar","malaria","B+","female",25,7,"3-8-2023");
     hosp_patients[9]=new patient("amna","dar","malaria","B+","female",25,7,"3-8-2023");
     hosp_patients[10]=new patient("amna","dar","malaria","B+","female",25,7,"3-8-2023");
     hosp_patients[11]=new patient("amna","dar","malaria","B+","female",25,7,"3-8-2023");


     }
      void showreg_patient(){
         cout<<endl<<endl<<"=====================================admitted patient data======================================="<<endl;
         for(int i=0;i<12;i++){
            cout<<endl<<endl;

            hosp_patients[i]->show();


         }

     }



void show_birthrecord(){
for(int i=0;i<5;i++){
        cout<<endl<<"                      ----------------------------                           "<<endl;
    birth_rec[i].show();
}

}
void show_deathrecord(){
for(int i=0;i<5;i++){
    cout<<endl<<"                               ----------------------------------                      "<<endl;
    death_rec[i].show();
}

}
doctor** getspecial_doc(){
return special_doc;        //--------------------------------------------------------PROBLEM----------------------------------------------------
}
/*void blood_inventory_data(){
inv.add_units();
inv.show_add_units();
inv.add_regular_donor();
inv.show_regular_donor();


}*/

//void online_user(){
////    cout<<endl<<"###enter the concern or disease and you would be recommended the respective doctor along with his/her timings###";
////    cout<<endl<<"           liver                        kidney                         oncology";
////    cout<<endl<<"           neurology                    cardiology                     gynaecology";
////    cout<<endl<<"           gastrointestine                                                      ";
//online_patient online_p;
//online_p.add_doc(special_doc);
//online_p.recommended_doctor();}
};
class user{
protected:
    string login;
    string password;
public:
    virtual string getlogin()=0;
    virtual string getpassword()=0;
    virtual void setlogin(string)=0;
    virtual void setpassword(string)=0;
    virtual void authority_menu()=0;


};
class admin:public user{
public:
    admin(string login,string password){
    this->login=login;
    this->password=password;
    }
    void setlogin(string a){
    login=a;
    }
    void setpassword(string a){
    password=a;

    }
    string getlogin(){
    return login;
    }
    string getpassword(){
    return password;
    }
    void authority_menu(){
        cout<<endl<<"                            **ADMIN'S ACCESS**"<<endl;
    cout<<"    1.ADD DOCTOR          2.ADD NURSE          3.VIEW ALL RECORD OF HOSPITAL     4.EXIT "<<endl;

    }

};

class reception:public user{
public:
    reception(string login,string password){
    this->login=login;
    this->password=password;
    }
    void setlogin(string a){
    login=a;
    }
    void setpassword(string a){
    password=a;

    }
    string getlogin(){
    return login;
    }
    string getpassword(){
    return password;
    }
    void authority_menu(){
    cout<<endl<<"                        **RECEPTIONIST ACCESS**"<<endl;
    cout<<endl<<"        1.VIEW ADMITTED PATIENTS              2.VIEW ON DUTY and SPECIALIZED DOCTORS    "<<endl;
    cout<<endl<<"        3.VIEW RECOMMENDED APPOINTMENTS       4.VIEW NURSES"<<endl;
    cout<<endl<<"        5.VIEW JUNITOTS/CUSTODIANS/SECURITY   6.ADD PATIENTS"<<endl;
    cout<<endl<<"        7.VIEW BIRTH RECORD                   8.VIEW DEATH RECORD"<<endl;
    cout<<endl<<"        9.PATIENT BILL CALCULATE              10.EXIT";
    }
};


                                 //--------------------------=========================================================//

int main()
{  user*userlogin_admin=new admin("naeem khan","123");
user*userlogin_reception=new reception("sania khan","123");
int howMany=0;
int howMany_p=0;
int count_n=0;
int permission=0;
int permission_p=0;
int permission_n=0;
std::string dummy;

    cout << endl<<"***********************************************************************************************************************************************"<<endl;
    cout<<endl<<"                                        WELCOME TO AL-SHIFA HOSPITAL                                                      "<<endl;
    cout<<endl<<"                                 a project under hospital management system                                             "<<endl;
    cout<<endl<<"*************************************************************************************************************************************************"<<endl;
    hospital hos("AL SHIFA HOSPITAL","15 LAKE ROAD LAHORE");
    string username_role;
    cout<<endl<<"enter your role --are you receptionist OR admin--  :";
    getline(cin,username_role);
    hos.addreg_patient();
     hos.addreg_doc();
    hos.addspecial_doc();
     hos.reg_nurse();
     hos.reg_additional();
    bool error_flag1=false;
    bool error_flag2=false;
    do{
    if(username_role=="reception"){
            //error_flag=true;
        string enter_login_reception;
        string enter_password_reception;
        cout<<endl<<"ENTER LOGIN IN FOR RECEPTION:";
        getline(cin,enter_login_reception);
        //cin.ignore();
        cout<<endl<<"ENTER PASSWORD:";
        getline(cin,enter_password_reception);
        if(enter_login_reception==userlogin_reception->getlogin() && enter_password_reception==userlogin_reception->getpassword()){
            error_flag1=true;
            //userlogin_reception->authority_menu();
            int menucount=0;
//            cout<<endl<<"enter the number:";
//            cin>>menucount;
            while(1){cin.ignore();
                    std::getline(std::cin, dummy);
            system("cls");
                userlogin_reception->authority_menu();
                    cout<<endl<<"enter the number:";
            cin>>menucount;
            if(menucount==1){
                //hos.addreg_patient();
    hos.showreg_patient();
            }
            else if(menucount==2){
                hos.hospDocShow();
            }
            else if(menucount==3){
                int onlineu=0;

/*cout<<endl<<"ENTER 1 IF YOU WANNA CONTINUE OTHERWISE PRESS 0";
cin>>onlineu;*/
cout<<endl<<"###enter the concern or disease and you would be recommended the respective doctor along with his/her timings###";
    cout<<endl<<"           liver                         renal                          oncology";
    cout<<endl<<"           neurology                    cardiology                     gynaecology";
    cout<<endl<<"           gastrointestine                                                      ";
//hos.online_user();
//online_patient online_p;
online_patient online_p;
online_p.add_doc(hos.getspecial_doc());
string diseaseset;
do{
//online_p.add_doc(hos.getspecial_doc());
online_p.recommended_doctor();
cout<<endl<<"ENTER 1 IF YOU WANNA CONTINUE OTHERWISE PRESS 0:";
cin>>onlineu;
if(onlineu==0){break;}
cout<<endl<<"ENTER DISEASE:";
cin>>diseaseset;
online_p.setdisease(diseaseset);

}while(onlineu==1);
            }
            else if(menucount==4){
                cout<<endl<<endl<<"************************************   NURSES OF HOSPITAL   *************************************************"<<endl;
    //hos.reg_nurse();
    hos.display_reg_nurse();
            }
            else if(menucount==5){
                cout<<endl<<endl<<"************************************   JANITORS/CUSTODIANS/SECURITY PERSONNELS   ******************************"<<endl;
    //hos.reg_additional();
    hos.show_reg_additional();
            }
            else if(menucount==6){
                cout<<endl<<endl<<endl<<"================================================================================================================================================"<<endl;
      cout<<"                YOU CAN A CAPCITY OF 7 MORE PATIENTS NOW IF YOU WANNA ADD PATIENTS THEN PRESS 1 ELSE PRESS 0      "<<endl;
      cout<<"========================================================================================================================================================"<<endl;
      //int permission_p=0;
      cout<<"press:";
      cin>>permission_p;
      //int howMany_p=0;

      if(permission_p==1){
            cout<<endl<<"how many:";
             cin>>howMany_p;
             hos.add_added_patient(howMany_p);
             /*cout<<endl<<"++++++++++++++++++++++++++++++++++++++added doctors++++++++++++++++++++++++++++++++++++++++++"<<endl;
             hos.show_added_doctor(howMany_p);*/

      }
            }
            else if(menucount==7){
                cout<<endl<<endl<<endl<<"*******************************************BIRTH RECORD OF HOSPITAL*****************************************************************************"<<endl;
hos.show_birthrecord();
            }
            else if(menucount==8){
                cout<<endl<<endl<<endl<<"*******************************************DEATH RECORD OF HOSPITAL*****************************************************************************"<<endl;
hos.show_deathrecord();
            }
            else if(menucount==9){
                cout<<"*******************************************************patient bill**********************************************************"<<endl;
patient bill_patient;
bill_patient.patient_bill_calculate();
//cout<<"check";
//cin.ignore();
//std::getline(std::cin, dummy);
//system("cls");
            }
            else if(menucount==10){
                    cin.ignore();
                    cout<<endl<<"enter your role --are you receptionist OR admin--  :";
                getline(cin,username_role);
                break;
            }



            }

        }
//        else{
//            cout<<endl<<"SORRY WRONG INFORMATION:(";
//            cout<<endl<<"enter your role --are you receptionist OR admin--  :";
//    getline(cin,username_role);
//        }


    }
//    cout<<endl<<"enter your role --are you receptionist OR admin--  :";
//    getline(cin,username_role);
    //====================================================admin
    if(username_role=="admin"){
            //error_flag=true;
        string enter_login_admin;
        string enter_password_admin;
        cout<<endl<<"ENTER LOGIN IN FOR admin:";
        getline(cin,enter_login_admin);
        cin.ignore();
        cout<<endl<<"ENTER PASSWORD:";
        getline(cin,enter_password_admin);
        if(enter_login_admin==userlogin_admin->getlogin() && enter_password_admin==userlogin_admin->getpassword()){
                error_flag2=true;
                int menucount2=0;
        while(1){cin.ignore();
                std::getline(std::cin, dummy);
            system("cls");
                userlogin_admin->authority_menu();
                cout<<endl<<"enter the number :";
        cin>>menucount2;
    //#hos.addreg_doc();
    //#hos.addspecial_doc();

//    hos.hospDocShow();
//
//    //hos.showspecial_doc();
//    //#hos.addreg_patient();
//    hos.showreg_patient();
//    cout<<endl<<endl<<"************************************   NURSES OF HOSPITAL   *************************************************"<<endl;
//    //#hos.reg_nurse();
//    hos.display_reg_nurse();
//    cout<<endl<<endl<<"************************************   JANITORS/CUSTODIANS/SECURITY PERSONNELS   ******************************"<<endl;
//    //#hos.reg_additional();
//    hos.show_reg_additional();
//    //hos.add_added_doctor();
    //9999999999999999999999999999999999999999999999999999999999999999
  //std::string dummy;
////    std::getline(std::cin, dummy);
//system("cls");
if(menucount2==1){
    cout<<endl<<endl<<endl<<"===================================================================================================================================================="<<endl;
      cout<<"                YOU CAN A MAXIMUM OF 5 MORE DOCTORS NOW IF YOU WANNA ADD DOCTOR THEN PRESS 1 ELSE PRESS 0      "<<endl;
      cout<<"======================================================================================================================================================"<<endl;
      //int permission=0;
      cout<<"press:";
      cin>>permission;
      //int howMany=0;

      if(permission==1){
            cout<<endl<<"how many:";
             cin>>howMany;
             hos.add_added_doctor(howMany);


      }}
      else if(menucount2==2){
        cout<<endl<<endl<<"***********************************YOU CAN ADD 5 MORE NURSES NOW IF YOU WANNA ADD PRESS 1 ELSE PRESS 0****************"<<endl;
        //int permission_n=0;
        cout<<endl<<"press:";
        cin>>permission_n;
        if(permission_n==1){
            //int count_n=0;
            cout<<endl<<"HOW MANY:";
            cin>>count_n;
            hos.reg_nurse(count_n);

        }

      }
      //--------------------------------------------added patients------------------------------------------------
//      cout<<endl<<endl<<endl<<"================================================================================================================================================"<<endl;
//      cout<<"                YOU CAN A CAPCITY OF 7 MORE PATIENTS NOW IF YOU WANNA ADD PATIENTS THEN PRESS 1 ELSE PRESS 0      "<<endl;
//      cout<<"========================================================================================================================================================"<<endl;
//      int permission_p=0;
//      cout<<"press:";
//      cin>>permission_p;
//      int howMany_p=0;
//
//      if(permission_p==1){
//            cout<<endl<<"how many:";
//             cin>>howMany_p;
//             hos.add_added_patient(howMany_p);
//             /*cout<<endl<<"++++++++++++++++++++++++++++++++++++++added doctors++++++++++++++++++++++++++++++++++++++++++"<<endl;
//             hos.show_added_doctor(howMany_p);*/
//
//      }
//      //9999999999999999999999999999999999
//
//    std::getline(std::cin, dummy);
//system("cls");
else if(menucount2==3){
      cout<<endl<<endl<<endl<<endl<<"*****************************RECORD OF HOSPITAL***********************************************************************************"<<endl;
      hos.hospDocShow();


    //cout<<endl<<"++++++++++++++++++++++++++++++++++++++added doctors++++++++++++++++++++++++++++++++++++++++++"<<endl;
             if(permission==1)
             {hos.show_added_doctor(howMany);}
             hos.showreg_patient();
             //cout<<endl<<"++++++++++++++++++++++++++++++++++++++added doctors++++++++++++++++++++++++++++++++++++++++++"<<endl;
             if(permission_p==1)
             {hos.show_added_patient(howMany_p);}
/*cout<<endl<<endl<<endl<<endl<<"*****************************BIRTH RECORD OF HOSPITAL*******************************************"<<endl;
hos.add_birth_record();
hos.show_birth_record();*/
cout<<endl<<endl<<endl<<"*******************************************BIRTH RECORD OF HOSPITAL*****************************************************************************"<<endl;
hos.show_birthrecord();
cout<<endl<<endl<<endl<<"*******************************************DEATH RECORD OF HOSPITAL*****************************************************************************"<<endl;
hos.show_deathrecord();
//9999999999999999999999999999999999999999999999

//    std::getline(std::cin, dummy);
//system("cls");
cout<<endl<<endl<<"************************************   NURSES OF HOSPITAL   *************************************************"<<endl;
    //#hos.reg_nurse();
    hos.display_reg_nurse();
    if(permission_n==1){
            cout<<endl<<"*************************NEWLY REGISTERED NURSES***********************"<<endl;
    hos.display_reg_nurse(count_n);}
    cout<<endl<<endl<<"************************************   JANITORS/CUSTODIANS/SECURITY PERSONNELS   ******************************"<<endl;
    //#hos.reg_additional();
    hos.show_reg_additional();

}
else if(menucount2==4)
    break;
}


}}}while(error_flag1==false || error_flag2==false);
//cout<<endl<<"**************************************online user*********************************************";
/*online_patient online_p;
online_p.recommended_doctor*/

//chrono::seconds pauseDuration(2);
//this_thread::sleep_for(pauseDuration);

   std::getline(std::cin, dummy);
system("cls");
//cout<<"*******************************************************patient bill**********************************************************"<<endl;
//patient bill_patient;
//bill_patient.patient_bill_calculate();
//bill_patient.show_patient_bill_calculate();

cout<<endl<<"BLOOD BANK SYSTEM";
//cout<<"*******************************************************patient bill**********************************************************"<<endl;
//patient bill_patient;
//bill_patient.patient_bill_calculate();
//cout<<"check";
//cin.ignore();
//std::getline(std::cin, dummy);
//system("cls");
//hos.blood_inventory_data();
bloodinventory inv;
cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&blood units of hospital&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
inv.add_units();
inv.show_add_units();
//string dummy;
cin.ignore();
std::getline(std::cin, dummy);
system("cls");
cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&blood donors of hospital&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
inv.add_regular_donor();
inv.show_regular_donor();
std::getline(std::cin, dummy);
system("cls");
//cout<<"*******************************************************patient bill**********************************************************"<<endl;
////patient bill_patient;
//bill_patient.patient_bill_calculate();endl
cout<<"BLOOD SEARCH"<<endl;
inv.blood_search();






    return 0;
}
