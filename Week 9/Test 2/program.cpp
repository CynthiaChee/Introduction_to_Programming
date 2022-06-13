#include "splashkit.h"
#include <string>
#include <vector>

using std::vector;
using namespace std;

struct customer_data
{
    string name;
    int id;
    int age;
    double spent_amount;
};

struct store_data
{
    string name;
    string location;
};

struct brand_kingdom
{
    store_data store;
    vector<customer_data> clients;
};

string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}
int read_integer(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}

int read_double(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_double(line);
}

customer_data gather_information()
{
    customer_data new_client;

    write_line("Collecting Information");
    new_client.name = read_string("Name: ");
    new_client.id = read_integer("ID: ");
    new_client.age = read_integer("Age: ");
    new_client.spent_amount = read_double("Purchase amount: ");

    return new_client;
}

void add_information(brand_kingdom &main)
{
    write_line("Collecting info");
    main.store.name = read_string("Enter store name: ");

    customer_data client;
    int num = 2;
    for (int i = 0; i<num; i++)
    {
        client = gather_information();
        main.clients.push_back(client);
    }
}

void write_information(const brand_kingdom &main)
{
    write_line("Full list of all customers in the database");
    for (int i =0; i <main.clients.size(); i++)
    {
        write(i+1);
        write_line(":" + main.clients[i].name);
    }
}

int main()
{
    brand_kingdom main;
    add_information(main);
    write_information(main);
    return 0;
}