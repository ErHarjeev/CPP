#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include <mysql.h>
#include <mysqld_error.h>
#include <limits>


using namespace std;

const char* HOST = "127.0.0.1";
const char* USER = "root";
const char* PW = "Changeme51";
const char* DB = "hostel_accommodation";
const char* TABLE = "hostel";
const unsigned int PORT = 3306;

string dbQuery;
MYSQL* db_connect;

class Hostel{
    string name;
    unsigned int bed, fee;
public:
    Hostel(string _name, int _bed, int _fee): name(_name), bed(_bed), fee(_fee)
    {

        // Connect with the Database.
        db_connect = mysql_init(NULL);
        if(mysql_real_connect(db_connect, HOST, USER, PW, DB, PORT, NULL, 0))
        {
            cout <<"==> Database connected" <<endl;
        }
        else
        {
            cout << "==> Database connection error." << mysql_error(db_connect) <<endl;
        }

        // Insert the new row in to the table.
        dbQuery = "INSERT INTO " + static_cast<std::string>(TABLE) + " (Name, Bed, Fee) VALUES ('" +  (this->get_name()) + "','" + std::to_string(this->get_bed()) + "','" + std::to_string(this->get_fee()) + "');" ;
        cout << "==> SQL Query:" << dbQuery << endl;
        if(mysql_query(db_connect,dbQuery.c_str()))
        {
            cout << "==> Error:" <<mysql_error(db_connect) << endl;
        }
        else
        {
            cout << "==> Row Inserted" <<endl;
        }
    }
    void set_name(string _name){
        name = _name;
    }
    void set_bed(int _bed){

        dbQuery = "UPDATE " + static_cast<std::string>(TABLE) + " SET Bed = " + std::to_string(_bed) + " WHERE Name = '" + this->get_name() + "';";
        cout << "==> SQL Query: " << dbQuery << endl;
        if(mysql_query(db_connect,dbQuery.c_str())) {
            cout << "==> Error: UPDATE Bed Query" <<mysql_error(db_connect);
        }

        bed = _bed;
    }
    void set_fee(int _fee){
        fee = _fee;
    }
    string get_name (void) const{
        return this->name;
    }
    unsigned int get_bed  (void) const{
        return this->bed;
    }
    unsigned int get_fee  (void) const{
        return this->fee;
    }

};

int main()
{
    Hostel boysHostel("ACE", 5, 500);
    bool exit = false;
    unsigned int inputVal = 0;      // Stores input form the user on console
    unsigned int availableBeds;
    MYSQL_RES *queryResult;
    MYSQL_ROW rowResult;

    while(!exit)
    {
        //system("cls");
        cout << "Welcome to Hostel Accommodation System" << endl;
        cout << "---------------------------------------" << endl;
        cout << "1. Reserve Bed: " << endl;
        cout << "2. Exit: " << endl;
        cout << "Enter your choice" << endl ;
        cin >> inputVal;

        switch(inputVal)
        {
            case 1: dbQuery = "SELECT Bed FROM "+ static_cast<std::string>(TABLE)+ " WHERE Name = '" + boysHostel.get_name() + "';";
                    cout << "==> SQL Query: " << dbQuery << endl;
                    if(mysql_query(db_connect,dbQuery.c_str()))
                    {
                        cout << "==> Error: Select Bed Query" <<mysql_error(db_connect);
                    }
                    else
                    {
                            // Get the value of result
                            queryResult = mysql_store_result(db_connect);
                            if(queryResult)
                            {
                                rowResult = mysql_fetch_row(queryResult);
                                if(rowResult)
                                {
                                    availableBeds = static_cast<unsigned int>(atoi(rowResult[0]));
                                }
                                else
                                {
                                    cout << "Error: Geting the Row Result" << mysql_error(db_connect) << endl;
                                }

                                if(availableBeds > 0)
                                {
                                    string getName;
                                    cout << "Enter Student Name : ";
                                    // Clear the input buffer
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    getline(cin, getName);

                                    availableBeds--;
                                    boysHostel.set_bed(availableBeds);

                                    cout << "Bed Booked for " << getName <<". Remaining Beds are " << availableBeds << endl;

                                }
                                else
                                {
                                    cout << "Sorry !!! No more bed is available";
                                }

                            }
                            else
                            {
                                cout << "Error: Getting Result" << mysql_error(db_connect) << endl;
                            }

                        }

                    break;
            case 2: exit = true;
                    break;
            default:
                    cout << "Invalid Input" <<endl;
                    break;
        }


    }

    mysql_free_result(queryResult);
    mysql_close(db_connect);

   return 0;
}


