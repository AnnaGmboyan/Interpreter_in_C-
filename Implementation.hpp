#ifndef IMPLEMENTATION_HPP
#define IMPLEMENTATION_HPP

#include <stack>

void  contains_main(std::map<int, std::vector<std::string>>& map)
{
		for ( int i = 0; i < lines_count; ++i)
		{
				if (map[i].size() == 2)
				{
						if( (map[i][0] == "int") && (map[i][1] == "main()"))
						{
								main_line = i;
								std::cout << "Main_line is: " << i << std::endl;

								return;
						}
				}
		}
	std::cout << "Can't find main() function" << std::endl;
		exit(0);

}

void valid_parentheses(std::map<int, std::vector<std::string>>& map)
{
    std::stack<std::string> st;
    int i = 0;

    // Checking parentheses before int main()
    for (i; i < main_line; ++i) 
    {
        if (map[i].size() == 1)
        {
            if (map[i][0] == "{" || map[i][0] == "}")
            {
                st.push(map[i][0]);
                break;
            }
        }
    }

    if (!st.empty())
    {
        std::cout << "You have an extra parenthesis in the following line: " << i << std::endl;
        exit(0);
    }

    // Checking if there are any code lines between int main() and first parenthesis
    int first_parenthesis_line = main_line;

    while (map[i][0] != "{" && map[i][0] != "}")
    {
        ++first_parenthesis_line;
		++i;
    }

    for (int k = main_line; k < first_parenthesis_line; ++k)
    {
        if (!map[k].empty())
        {
            std::cout << "Expected initializer before line: " << k << std::endl;
            exit(0);
        }
    }

    // Checking the validity of parentheses after int main()
    for (int k = first_parenthesis_line; k < lines_count; ++k)
    {
        if (map[k].size() == 1)
        {
            if (map[k][0] == "{")
            {
                st.push(map[k][0]);
            }
            else
            {
                if (st.empty())
                {
                    std::cout << "Invalid parenthesis in line " << k;
                    exit(0);
                }

                if (map[k][0] == "}" && st.top() == "{")
                {
                    st.pop();
                }
                else
                {
                    std::cout << "Invalid parenthesis in line " << k;
                    exit(0);
                }
            }
        }
    }

    if (!st.empty())
    {
        std::cout << "Expected } to match {. ";
    }
}
#endif //IMPLEMENTATION_HPP
