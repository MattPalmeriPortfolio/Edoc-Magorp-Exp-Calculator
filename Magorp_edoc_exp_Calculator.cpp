#include <iostream>
using namespace std; 

//this program determines the maximum XP the user can earn from evolving edocs, based on an input of their initial # of edocs and candy

int main(){
	// initialize
	int candy(0), edoc(0), margorp(0), experience(0), evolutions(0);
	char prompt;
	const int EVO_REQ_CANDY(12), EVO_GIVE_CANDY(1), EVO_GIVE_XP(500), TRANSFER_REWARD(1);
	// begin program
	// prompt user
	cout << "This fanmade tool will figure out the max XP you can get from evolving edoc.\n";
	do {
		cout << "Enter the amount of candy you currently have\n";
		cin >> candy;
		cout << "Enter the amount of edoc you currently have\n";
		cin >> edoc;
		while (((candy + ((edoc - 1) * TRANSFER_REWARD) + (margorp * TRANSFER_REWARD)) >= EVO_REQ_CANDY) && (edoc >= 1)) //while it is still possible to evolve more edoc
		{
			evolutions = 0;
			if ((candy >= EVO_REQ_CANDY) && (edoc >= (candy / EVO_REQ_CANDY))) //if candy is higher than requirements, can just get an evo
			{
				evolutions = candy / EVO_REQ_CANDY;
				experience += (evolutions * EVO_GIVE_XP);
				candy = ((candy % EVO_REQ_CANDY) + (evolutions * EVO_GIVE_CANDY));
				edoc -= evolutions; margorp += evolutions;
				cout << "Evolve " << evolutions << " Edoc to end up with\n"
					<< candy << " candy, " << edoc << " Edoc, and " << margorp << " Margorp\n";
			}
			else if ((margorp > 0) && (((margorp * TRANSFER_REWARD) + ((edoc - 1) * TRANSFER_REWARD) + candy) >= EVO_REQ_CANDY)) //if there are margorp and at least 1 edoc to evolve after transfers
			{
				int difference = EVO_REQ_CANDY - candy, mgtransfers = 0, edtransfers = 0;
				for (margorp; ((margorp > 0) && (difference > 0)); margorp--) //loop through transferring margorps until out of margorps or have enough candy to evolve
				{
					difference -= TRANSFER_REWARD;
					mgtransfers++;
					candy += TRANSFER_REWARD;
				}
				if (difference > 0) //if margorps aren't enough, transfer edocs
				{
					for (edoc; ((edoc > 0) && (difference > 0)); edoc--)
					{
						difference -= TRANSFER_REWARD;
						edtransfers++;
						candy += TRANSFER_REWARD;
					}
				}
				cout << "Transfer " << mgtransfers << " Margorp and " << edtransfers << " Edoc to end up with\n"
					<< candy << " candy, " << edoc << " Edoc, and " << margorp << " Margorp\n";
			}
			else if ((((edoc - 1) * TRANSFER_REWARD) + candy) >= EVO_REQ_CANDY) //if there are no margorp but evo is possible through transferring edoc
			{
				int difference = EVO_REQ_CANDY - candy, transfers = 0;
				for (edoc; ((edoc > 0) && (difference > 0)); edoc--)
				{
					difference -= TRANSFER_REWARD;
					transfers++;
					candy += TRANSFER_REWARD;
				}
				cout << "Transfer " << transfers << " Edoc to end up with\n"
					<< candy << " candy, " << edoc << " Edoc, and " << margorp << " Margorp\n";
			}
		}
		cout << "Total experience: " << experience << endl;
		//prompt to continue
		cout << "Try again? Y to continue, N to end\n";
		cin >> prompt;
		margorp = 0; experience = 0;
	} while (prompt == 'Y' || prompt == 'y');
	cout << "Goodbye!\n";
	return 0;
}

