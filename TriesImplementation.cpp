#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Node
{
	char character;
	bool string_present;
	vector<Node*> next;
};
class Tries
{
	public:
	Node* root;
	bool insertString(string s)
	{
		bool result = false;
		Node* current = root;
		if(s.length()==0)
		{
			root->string_present = true;
		}
		else
		{
			int i=0;
			for(;i<s.length();i++)
			{
			    bool found = false;
				for(vector<Node*>::iterator it=current->next.begin();it!=current->next.end();it++)
				{
					if((*it)->character == s[i])
					{
						//cout<<(*it)->character;
						current = (*it);
						found = true;
						if(current->string_present)
						{
							result = true;
						}
						break;
					}
					//cout<<s[i];
					//cout<<"|";
				}
				if(!found)
				{
					break;
				}
			}
			//cout<<s[i];
			if(i==s.length())
			{
				current->string_present = true;
			}
			else
			{
			    for(;i<s.length();i++)
			    {
			    	Node* new_node = new Node;
			    	new_node->character = s[i];
			    	new_node->string_present = false;
			    	new_node->next.resize(0);
			    	current->next.push_back(new_node);
			    	current = new_node;
				}
				current->string_present = true;
		    }
		}
		//cout<<endl;
		return result;
	}
	bool find_string(string s, Node* current)
	{
		if(s.length()==0)
		    return current->string_present;
		bool found = false;
		for(vector<Node*>::iterator it = current->next.begin(); it!=current->next.end(); it++)
		{
		    if((*it)->character==s[0])
			    found = true;
		    if(found)
			{
			    if(s.length()==1)
				    return (*it)->string_present;
				else
				    return find_string(s.substr(1),(*it));
			}	
		}
		return found;
	}
	Tries()
	{
		root = new Node;
		root->character = ' ';
		root->string_present = false;
		root->next.resize(0);
	}
};
int main()
{
    Tries T;
	cout<<T.insertString("aaaa")<<endl;
	cout<<T.insertString("aa")<<endl;
	cout<<T.insertString("abcde")<<endl;
	cout<<T.insertString("aabcde")<<endl;
	cout<<T.insertString("cedaaa")<<endl;
	cout<<T.insertString("jabjjjad")<<endl;
	
	/*T.insertString("");
	cout<<T.find_string("a",T.root)<<endl;
	cout<<T.find_string("",T.root)<<endl;
	cout<<T.find_string("ab",T.root)<<endl;
	cout<<T.find_string("b",T.root);*/	
	return 0;
}
