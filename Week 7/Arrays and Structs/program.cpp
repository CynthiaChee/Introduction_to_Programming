#include "splashkit.h"
#include <string>
#include <vector>

using std::vector;
using namespace std;

struct knight_data
{
    string name;
    int age;
    vector<string> tool;
};

struct kingdom_data
{
    string name;
    vector<knight_data> knights;
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

enum knight_update_option  //Options to update knight details
{
    UPDATE_NAME,
    UPDATE_AGE,
    ADD_TOOL,
    DELETE_TOOL,
    FINISH_UPDATE
};

enum kingdom_update_option  //Options to update kingdom details
{
    ADD_KNIGHT,
    QUERY_KNIGHT,
    DELETE_KNIGHT,
    UPDATE_KNIGHT,
    DISPLAY_KINGDOM,
    EXIT
};

knight_update_option read_knight_update_option()  //Allows the player to select value to update
{
    int result;

        write_line("1: Update name");
        write_line("2. Update age");
        write_line("3. Add tool");
        write_line("4. Delete tool");
        write_line("5. Finish update");
        result = read_integer("Select option: ");
        
        return static_cast<knight_update_option>(result - 1);
}

kingdom_update_option read_kingdom_update_option()  //Allows the player to select value to update
{
    int result;

        write_line("1: Add knight");
        write_line("2. Query knight");
        write_line("3. Delete knight");
        write_line("4. Update knight");
        write_line("5. Display kingdom");
        write_line("6. Exit");
        result = read_integer("Select option: ");
        
        return static_cast<kingdom_update_option>(result - 1);
}


int knight_idx(const kingdom_data &kingdom)
{
    for(int i = 0; i < kingdom.knights.size(); i++)
    {    
        if(i >= 0 and i <= kingdom.knights.size())
        {
            int idx = i + 1;
            return idx;
        }
    }
}

void write_tools(const knight_data &knight)
{
    int i;
    for(i = 0; i < knight.tool.size(); i++)
    {
        write_line(knight.tool[i]);
    }
}

void write_knight(const knight_data &knight)  //Outputs knight details
{
    write_line(knight.name + " aged " + to_string(knight.age));
    if (knight.tool.empty())
    {
        write_line("This knight has no tools");
    }
    else 
    {
        write_line(knight.name + " has the following tool(s): ");
        write_tools(knight);
    }
}

knight_data read_knight()  //Enter details for one knight
{
    knight_data result;
    result.name = read_string("Enter name: ");
    result.age = read_integer("Enter age: ");
    int entries = read_integer("How many tools do you want to enter?: ");

    while(result.tool.size() < entries)
    {
        result.tool.push_back(read_string("Enter a tool: "));
    }
    return result;
}

void add_knight(kingdom_data &kingdom)  //Adds a new knight with details
{
    knight_data new_knight;
    new_knight = read_knight();
    kingdom.knights.push_back(new_knight);
}

void add_tool(knight_data &knight)   //Adds a tool for a knight
{
    int more_tools = read_integer("How many tools do you want to enter?: ");
    int target = knight.tool.size() + more_tools;
    while(knight.tool.size() < target)
    {
        knight.tool.push_back(read_string("Enter a tool: "));
    }
}


void delete_tool(knight_data &knight)  //Deletes a tool
{
    int tool_index;
    int tool_to_delete;
    tool_to_delete = read_integer("Select tool to delete: ");
    tool_index = tool_to_delete - 1;
    if (knight.tool.empty())
    {
        write_line("This knight has no tools");
    }
    else if (tool_index >= 0 and tool_index <= knight.tool.size())
    {
        int last_tool_idx;
        last_tool_idx = knight.tool.size() - 1;
        knight.tool[tool_index] = knight.tool[last_tool_idx];
        knight.tool.pop_back();
    }
}

void write_kingdom(const kingdom_data &kingdom)  //Lists down the knights in the kingdom
{
    int knight_no = knight_idx(kingdom);
    write_line("==================");
    write_line(kingdom.name);
    write_line("==== Knights ====");
    if(kingdom.knights.empty())
    {
        write_line("There are no knights in this kingdom.");
    }

    for(int i = 0; i < kingdom.knights.size(); i++)
    {
        write(to_string(knight_no) + ". ");
        knight_no++;
        write_knight(kingdom.knights[i]);
    }
    write_line("==================");
}

int select_knight(const kingdom_data &kingdom)  //Selects a knight
{
    write_kingdom(kingdom);
    int i;
    i = read_integer("Select knight: ");
    if(i > 0 and i <= kingdom.knights.size())
    {
        int idx = i-1;
        return idx;
    }
    else
    {
        write_line("Invalid selection");
    }
}

void delete_knight(kingdom_data &kingdom)  //Deletes a knight
{
    int index;
    index = select_knight(kingdom);
    if (index >= 0 and index <= kingdom.knights.size())
    {
        int last_idx;
        last_idx = kingdom.knights.size() - 1;
        kingdom.knights[index] = kingdom.knights[last_idx];
        kingdom.knights.pop_back();
    }
    
}

void query_knight(kingdom_data &kingdom)  //Returns the details of a particular knight
{
    int i;
    i = select_knight(kingdom);
    if(i > 0)
    {
        write_knight(kingdom.knights[i]);
    }
}


void update_knight(kingdom_data &kingdom)   //Update knight details according to user's choice
{
    knight_update_option option;
    int index_knight;
    index_knight = select_knight(kingdom);
    do
    {
        write_line();
        write_line("== Update Knight ==");
        write_knight(kingdom.knights[index_knight]);
        write_line();
        option = read_knight_update_option();

        switch(option)
        {
            case UPDATE_NAME:
            kingdom.knights[index_knight].name = read_string("Enter new name ");
            break;
            case UPDATE_AGE:
            kingdom.knights[index_knight].age = read_integer("Enter new age ");
            break;
            case ADD_TOOL:
            add_tool(kingdom.knights[index_knight]);
            break;
            case DELETE_TOOL:
            delete_tool(kingdom.knights[index_knight]);
            break;
            case FINISH_UPDATE:
            write_kingdom(kingdom);
            break;
            default:
            write_line("Please select a valid option");
        }
    } while (option != FINISH_UPDATE);
    
}

void update_kingdom(kingdom_data &kingdom)      //Update kingdom details according to user's choice
{
    kingdom_update_option option;
    do
    {
        write_line();
        write_line("== Update Kingdom ==");
        write_line();
        option = read_kingdom_update_option();

        switch(option)
        {
            case ADD_KNIGHT:
            add_knight(kingdom);
            break;
            case QUERY_KNIGHT:
            query_knight(kingdom);
            break;
            case DELETE_KNIGHT:
            delete_knight(kingdom);
            break;
            case UPDATE_KNIGHT:
            update_knight(kingdom);
            break;
            case DISPLAY_KINGDOM:
            write_kingdom(kingdom);
            break;
            case EXIT:
            break;
            default:
            write_line("Please select a valid option");
        }
    } while (option != EXIT);
    
}

int main()
{
    kingdom_data kingdom;
    knight_data knight;
    kingdom.name = read_string("Enter kingdom name: ");

    write_kingdom(kingdom);
    update_kingdom(kingdom);
    return 0;
}