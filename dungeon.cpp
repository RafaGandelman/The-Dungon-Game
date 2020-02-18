//This is the game

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"Dice.h"
#include"Map.h"
#include"Barbarian.h"
#include"Rogue.h"
#include"Wizard.h"
#include"Monster.h"
using namespace std;
//  g++ -std=c++11 Monster.cpp Dice.cpp Character.cpp Map.cpp Barbarian.cpp Rogue.cpp Wizard.cpp dungeon.cpp -o Dungeon.out
//  ./Dungeon.out

void split (string mother , char delimiter , string currentLine[]);

//Prints menu for createChar function
char createMenu()
{
    string sOut;
    char out;
    while (true)
    {
        cout << "---------------------------------------" << endl;
        cout << "Please select an option:" << endl;
        cout << "n - New Game" << endl;
        cout << "l - Load Game" << endl;
        cout << "w - Wall of adventurers" << endl;
        cout << "q - Quit" << endl;
        cout << "---------------------------------------" << endl;
        getline(cin,sOut);
        out = sOut[0];
        if (out == 'w' || out == 'W' || out == 'n' || out == 'N' || out == 'l' || out == 'L' || out == 'q' || out == 'Q')
        {
            out = tolower(out);
            return out;
        }
        cout << "Invalid option. Please enter a valid option." << endl;
    }
}

//Prints menu for player to choose a class
char choiceMenu(string name)
{
    string sOut;
    char out;
    while (true)
    {
        cout << "---------------------------------------" << endl;
        cout << "What's your class " << name << "?" << endl;
        cout << "b - Barbarian" << endl;
        cout << "r - Rogue" << endl;
        cout << "w - Wizard" << endl;
        cout << "---------------------------------------" << endl;
        getline(cin,sOut);
        out = sOut[0];
        if (out == 'w' || out == 'W' || out == 'r' || out == 'R' || out == 'b' || out == 'B')
        {
            out = tolower(out);
            return out;
        }
        cout << "Invalid option. Please enter a valid option." << endl;
    }
}

void wallOfAdventurers()
{
    ifstream inFile;
    inFile.open("dungeonLoad.txt");
    if (inFile.fail())
    {
        cout << "Missing dungeonLoad.txt" << endl;
        exit(0);
    }
    string line;
    string currentLine[16];
    vector<string> name;
    vector<int> gold;
    string holder;
    while(getline(inFile,line))
    {
        if (line != "")
        {
            split(line , ',' , currentLine);
            if (currentLine[0] != "0name")
            {
                holder = currentLine[0] + ": " + currentLine[2] + " gold";
                name.push_back(holder);
                gold.push_back(stoi(currentLine[2]));
            }
        }
    }
    bool order = false;
    string nameTop;
    string nameBot;
    int goldTop;
    int goldBot;
    while (order == false)
    {
        order = true;
        for(int i = gold.size() - 1 ; i > 0 ; i--)
        {
            if (gold[i] > gold[i-1])
            {
                goldBot = gold[i];
                goldTop = gold[i-1];
                gold[i] = goldTop;
                gold[i-1] = goldBot;
                nameBot = name[i];
                nameTop = name[i-1];
                name[i] = nameTop;
                name[i-1] = nameBot;
                order = false;
            }
        }
    }
    cout << "---------------------------------------" << endl;
    for (int i = 1 ; i <= gold.size() ; i++)
    {
        cout << i << " - " << name[i-1] << endl;
    }
}

//Allows the player to create a new game, load an old game , see the ranking or quit the game
char createChar(Barbarian &bar , Rogue &rog , Wizard &wiz , Map &guide)
{
    char out;
    char choice;
    out = createMenu();
    switch(out)
    {
        //Setting a new hero
        case 'n':
        {
            cout << "Welcome adventurer to The Dungeon!" << endl;
            string newName;
            bool comma = true;
            while (comma != false)
            {
                cout << "What is your name hero?" << endl;
                getline(cin,newName);
                comma = false;
                if (newName.length() == 0)
                {
                    cout << "No name is not a name hero. Please enter a valid name." << endl;
                    comma = true;
                }
                for (int i = 0 ; i < newName.length() ; i++)
                {
                    if (newName[i] == ',')
                    {
                        cout << "Your name can't contain a comma. Please enter a valid name." << endl;
                        comma = true;
                        break;
                    }
                }
            }
            choice = choiceMenu(newName);
            if (choice == 'b')
            {
                bar.setName(newName);      
            }
            if (choice == 'r')
            {
                rog.setName(newName);              
            }
            if (choice == 'w')
            {
                wiz.setName(newName);
            }
            cout << "Welcome " << newName << " to The Dungeon!" << endl;
            return choice;
            break;
        }
        //Loading an previous hero that is alive
        case 'l':
        {
            ifstream inFile;
            inFile.open("dungeonLoad.txt");
            if (inFile.fail())
            {
                cout << "Missing dungeonLoad.txt" << endl;
                exit(0);
            }
            string line;
            string currentLine[16];
            vector<string> charName;
            vector<string> charHealth;
            vector<string> charLevel;
            while(getline(inFile,line))
            {
                if (line != "")
                {
                    split(line, ',' , currentLine);
                    if (currentLine[13] == "alive")
                    {
                        charName.push_back(currentLine[0]);
                        charHealth.push_back(currentLine[1]);
                        charLevel.push_back(currentLine[4]);
                    }
                }
            }
            inFile.close();
            //Diplays a list of the heros that are alive
            cout << "---------------------------------------" << endl;
            for (int i = 0 ; i < charHealth.size() ; i++)
            {
                cout << "- " << charName[i] << ", " << charHealth[i] << " health, level " << charLevel[i] << endl;
            }
            cout << "---------------------------------------" << endl;
            string heroName;
            bool match = false;
            while (match == false)
            {
                cout << "What's your name hero?" << endl;
                getline(cin,heroName);
                for (int i = 0 ; i < charHealth.size() ; i++)
                {
                    if (heroName == charName[i])
                    {
                        match = true;
                        break;
                    }
                }
                if (match == false)
                {
                    cout << "This hero isn't in The Dungeon. Please choose someone that is in The Dungeon." << endl;
                }
            }
            inFile.open("dungeonLoad.txt");
            while(getline(inFile, line))
            {
                if (line != "")
                {
                    split(line, ',' , currentLine);
                    if (currentLine[0] == heroName)
                    {
                        break;
                    }
                }
            }
            //Setting the hero based on class
            string hold;
            hold = currentLine[3];
            choice = tolower(hold[0]);
            if (choice == 'b')
            {
                bar.setName(heroName);
                for (int i = 1 ; i < stoi(currentLine[4]) ; i++)
                {
                    bar.levelUp();
                }
                bar.setHealth(-1*(bar.getHealth()));
                bar.setHealth(stoi(currentLine[1]));
                bar.changeGold(stoi(currentLine[2]));
                bar.setRageCount(stoi(currentLine[5]));
                bar.setTerrifyCount(stoi(currentLine[6]));
                bar.setRecklessCount(stoi(currentLine[7]));
            }
            if (choice == 'r')
            {
                rog.setName(heroName);
                for (int i = 1 ; i < stoi(currentLine[4]) ; i++)
                {
                    rog.levelUp();
                }
                rog.setHealth(-1*(rog.getHealth()));
                rog.setHealth(stoi(currentLine[1]));
                rog.changeGold(stoi(currentLine[2]));
                rog.setAssassinate(stoi(currentLine[8]));
                rog.setPoison(stoi(currentLine[9]));
            }
            if (choice == 'w')
            {
                wiz.setName(heroName);
                for (int i = 1 ; i < stoi(currentLine[4]) ; i++)
                {
                    wiz.levelUp();
                }
                wiz.setHealth(-1*(wiz.getHealth()));
                wiz.setHealth(stoi(currentLine[1]));
                wiz.changeGold(stoi(currentLine[2]));
                wiz.setFireball(stoi(currentLine[10]));
                wiz.setMagicMissile(stoi(currentLine[11]));
                wiz.setMageArmor(stoi(currentLine[12]));
            }
            //setting the map
            guide.setMapLevel(stoi(currentLine[4]));
            guide.setLocation(stoi(currentLine[14]) , stoi(currentLine[15]));
            cout << "Welcome " << heroName << " back to The Dungeon!" << endl;
            return choice;
            break;
        }
        //Displays the scoreboard
        case 'w':
        {
            wallOfAdventurers();
            createChar(bar , rog , wiz , guide);
            break;
        }
        //Quits the game
        case 'q':
        {
            cout << "Thank you for playing The Dungeon!" << endl;
            exit(0);
            break;
        }
        default:
        {
            break;
        }
    }
}

//Rolls increasingly more dice until a natural 1 is rolled
//The more rounds pass, the more likely it is to roll a 1
int fightCheck(int fightCounter)
{
    Dice chance;
    for (int i = 0 ; i < fightCounter ; i++)
    {
        if (chance.d20() == 1)
        {
            return true;
        }
    }
    return false;
}

//Menu of fight function
char fightMenu()
{
    string sOut;
    char out;
    while (true)
    {
        cout << "---------------------------------------" << endl;
        cout << "What action will you take hero?" << endl;
        cout << "a - Attack" << endl;
        cout << "s - Skill" << endl;
        cout << "f - Flee" << endl;
        cout << "---------------------------------------" << endl;
        getline(cin,sOut);
        out = sOut[0];
        if (out == 'a' || out == 'A' || out == 's' || out == 'S' || out == 'f' || out == 'F')
        {
            out = tolower(out);
            return out;
        }
        cout << "Invalid option. Please enter a valid option." << endl;
    }
}

//Randomly selects a monster from monsterManual.txt
void monsterRand(Monster &mon , Map guide)
{
    Dice chance;
    int holder = 0;
    int low = 6;
    if (guide.getMapLevel() == 1)
    {
        for (int i = 0 ; i < 5 ; i++)
        {
            holder = chance.d6();
            if (holder < low)
            {
                low = holder;
            }
        }
        mon.setMonster(low);
        return;
    }
    if (guide.getMapLevel() == 2)
    {
        for (int i = 0 ; i < 2 ; i++)
        {
            holder = chance.d6();
            if (holder < low)
            {
                low = holder;
            }
        }
        mon.setMonster(low);
        return;
    }
    low = 0;
    if (guide.getMapLevel() == 3)
    {
        for (int i = 0 ; i < 5 ; i++)
        {
            holder = chance.d6();
            if (holder > low)
            {
                low = holder;
            }
        }
        mon.setMonster(low);
        return;
    }
}

//Fight function creates a round system in which the player will perform their action and then the monster will attack 
//until either the player or the monster have zero or less health, or the player flees
void fight(Barbarian &bar , Rogue &rog , Wizard &wiz , Monster &mon , Map guide , char choice)
{
    char action;
    int skillInt = 0;
    int damage = 0;
    Dice chance;
    cout << "A " << mon.getName() << " runs out of the shaddows to attack you!" << endl;
    //Different clases have different attacks and skills
    if (choice == 'b')
    {
        while (bar.getHealth() > 0 && mon.getHealth() > 0)
        {
            bar.printCharSheet();
            action = fightMenu();
            
            switch(action)
            {
                //Normal attack
                case 'a':
                {
                    cout << "---------------------------------------" << endl;
                    mon.takeDamage(bar.attack(mon.getArmorClass()));
                    break;
                }
                //Special skill, based on class
                case 's':
                {
                    skillInt = bar.skill(mon.getArmorClass());
                    switch(skillInt)
                    {
                        case -1:
                        {
                            fight(bar , rog , wiz , mon , guide , choice);
                            return;
                            break;
                        }
                        case -2:
                        {
                            break;
                        }
                        default:
                        {
                            mon.takeDamage(skillInt);
                            break;
                        }
                    }
                    break;
                }
                //They player can try to escape the fight
                case 'f':
                {
                    cout << "---------------------------------------" << endl;
                    damage = 0;
                    //If the monster hits (meaning damage is greater than zero)
                    damage = mon.attack(bar.getArmorClass());
                    if (damage > 0)
                    {
                        //The player can't escape the fight (they can still try again in the next round)
                        bar.takeDamage(damage);
                        cout << "You are unnable to escape as the monster hits you!" << endl;
                        bar.untoggleRage();
                        break;
                    }
                    cout << "But you manage to dodge the attack and run away" << endl;
                    return;
                }
            }
            //If the palyer died trying to escape or the monster died due to an enemy attack
            if (bar.getHealth() <= 0 || mon.getHealth() <= 0) 
            {
                break;
            }
            if (bar.getTerrifyToggle() == true)
            {
                bar.useTerrify();
                cout << "---------------------------------------" << endl;
                cout << "Congratulations! The " << mon.getName() << " ran away!" << endl;
                bar.untoggleRage();
                int gold = 0;
                gold = (guide.getMapLevel()*chance.dSpecific(50));
                cout << "As the " << mon.getName() << " fled, it dropped " << gold << " gold coins!" << endl;
                bar.changeGold(gold);
                break;
            }
            cout << "---------------------------------------" << endl;
            //Monster attack
            bar.takeDamage(mon.attack(bar.getArmorClass()));
        }
        //Player won the fight and now receives gold as reward
        if (bar.getHealth() > 0 && mon.getHealth() <= 0)
        {
            cout << "---------------------------------------" << endl;
            cout << "Congratulations! The " << mon.getName() << " is dead!" << endl;
            bar.untoggleRage();
            int gold = 0;
            gold = (guide.getMapLevel()*chance.dSpecific(50));
            cout << "In the " << mon.getName() << " remains you find " << gold << " gold coins!" << endl;
            bar.changeGold(gold);
        }
    }
    if (choice == 'r')
    {
        while (rog.getHealth() > 0 && mon.getHealth() > 0)
        {
            rog.printCharSheet();
            action = fightMenu();
            switch(action)
            {
                //Normal attack
                case 'a':
                {
                    cout << "---------------------------------------" << endl;
                    mon.takeDamage(rog.attack(mon.getArmorClass()));
                    break;
                }
                //Special skill, based on class
                case 's':
                {
                    skillInt = rog.skill(mon.getArmorClass());
                    switch(skillInt)
                    {
                        case -1:
                        {
                            fight(bar , rog , wiz , mon , guide , choice);
                            return;
                            break;
                        }
                        case -2:
                        {
                            break;
                        }
                        default:
                        {
                            mon.takeDamage(skillInt);
                            break;
                        }
                    }
                    break;
                }
                //They player can try to escape the fight
                case 'f':
                {
                    cout << "---------------------------------------" << endl;
                    damage = 0;
                    //If the monster hits (meaning damage is greater than zero)
                    damage = mon.attack(rog.getArmorClass());
                    if (damage > 0)
                    {
                        //The player can't escape the fight (they can still try again in the next round)
                        rog.takeDamage(damage);
                        cout << "You are unnable to escape as the monster hits you!" << endl;
                        break;
                    }
                    cout << "But you manage to dodge the attack and run away" << endl;
                    if (rog.getPoisonActive() == true)
                    {
                        rog.setPoisonActive();
                    }
                    return;
                }
            }
            //If the palyer died trying to escape or the monster died due to an enemy attack
            if (rog.getHealth() <= 0 || mon.getHealth() <= 0) 
            {
                break;
            }
            cout << "---------------------------------------" << endl;
            //Monster attack
            rog.takeDamage(mon.attack(rog.getArmorClass()));
        }
        //Player won the fight and now receives gold as reward
        if (rog.getHealth() > 0 && mon.getHealth() <= 0)
        {
            cout << "---------------------------------------" << endl;
            cout << "Congratulations! The " << mon.getName() << " is dead!" << endl;
            if (rog.getPoisonActive() == true)
            {
                rog.setPoisonActive();
            }
            int gold = 0;
            gold = (guide.getMapLevel()*chance.dSpecific(50));
            cout << "In the " << mon.getName() << " remains you find " << gold << " gold coins!" << endl;
            rog.changeGold(gold);
        }
    }
    if (choice == 'w')
    {
        while (wiz.getHealth() > 0 && mon.getHealth() > 0)
        {
            wiz.printCharSheet();
            action = fightMenu();
            
            switch(action)
            {
                //Normal attack
                case 'a':
                {
                    cout << "---------------------------------------" << endl;
                    mon.takeDamage(wiz.attack(mon.getArmorClass()));
                    break;
                }
                //Special skill, based on class
                case 's':
                {
                    skillInt = wiz.skill(mon.getArmorClass());
                    switch(skillInt)
                    {
                        case -1:
                        {
                            fight(bar , rog , wiz , mon , guide , choice);
                            return;
                            break;
                        }
                        case -2:
                        {
                            break;
                        }
                        default:
                        {
                            mon.takeDamage(skillInt);
                            break;
                        }
                    }
                    break;
                }
                //They player can try to escape the fight
                case 'f':
                {
                    cout << "---------------------------------------" << endl;
                    damage = 0;
                    //If the monster hits (meaning damage is greater than zero)
                    damage = mon.attack(wiz.getArmorClass());
                    if (damage > 0)
                    {
                        //The player can't escape the fight (they can still try again in the next round)
                        wiz.takeDamage(damage);
                        cout << "You are unnable to escape as the monster hits you!" << endl;
                        break;
                    }
                    cout << "But you manage to dodge the attack and run away" << endl;
                    wiz.setArmorClass(10+wiz.getLevel());
                    return;
                }
            }
            //If the palyer died trying to escape or the monster died due to an enemy attack
            if (wiz.getHealth() <= 0 || mon.getHealth() <= 0) 
            {
                break;
            }
            cout << "---------------------------------------" << endl;
            //Monster attack
            wiz.takeDamage(mon.attack(wiz.getArmorClass()));
        }
        //Player won the fight and now receives gold as reward
        if (wiz.getHealth() > 0 && mon.getHealth() <= 0)
        {
            cout << "---------------------------------------" << endl;
            cout << "Congratulations! The " << mon.getName() << " is dead!" << endl;
            wiz.setArmorClass(10+wiz.getLevel());
            int gold = 0;
            gold = (guide.getMapLevel()*chance.dSpecific(50));
            cout << "In the " << mon.getName() << " remains you find " << gold << " gold coins!" << endl;
            wiz.changeGold(gold);
        }
    }
}

void bossRand(Monster &mon , Map guide)
{
    if (guide.getMapLevel() == 1)
    {
        mon.setHealth(-1*(mon.getHealth()));
        mon.setHealth(30);
        mon.setName("Rohga, The Oozing Shadow");
        mon.setDamageDie(8);
        mon.setBonus(3);
        mon.setArmorClass(14);
        mon.setDesciption("It swings its poison covered claws towards you!");
        return;
    }
    if (guide.getMapLevel() == 2)
    {
        mon.setHealth(-1*(mon.getHealth()));
        mon.setHealth(45);
        mon.setName("Agatha, The Death Witch");
        mon.setDamageDie(8);
        mon.setBonus(4);
        mon.setArmorClass(15);
        mon.setDesciption("It regurgitates a ball of black flames towards you!");
    }
    if (guide.getMapLevel() == 3)
    {
        mon.setHealth(-1*(mon.getHealth()));
        mon.setHealth(100);
        mon.setName("Brandrax'Il, The Infernal Flame");
        mon.setDamageDie(10);
        mon.setBonus(5);
        mon.setArmorClass(16);
        mon.setDesciption("It swings its magma covered claws towards you!");
    }
}

char bossFightMenu()
{
    string sOut;
    char out;
    while (true)
    {
        cout << "---------------------------------------" << endl;
        cout << "What action will you take hero?" << endl;
        cout << "a - Attack" << endl;
        cout << "s - Skill" << endl;
        cout << "---------------------------------------" << endl;
        getline(cin,sOut);
        out = sOut[0];
        if (out == 'a' || out == 'A' || out == 's' || out == 'S')
        {
            out = tolower(out);
            return out;
        }
        if (out == 'f' || out == 'F')
        {
            cout << "You can't flee from a boos fight. Player enter a valid option." << endl;
        }
        cout << "Invalid option. Please enter a valid option." << endl;
    }
}

//Fight function creates a round system in which the player will perform their action and then the monster will attack 
//until either the player or the monster have zero or less health, or the player flees
void bossFight(Barbarian &bar , Rogue &rog , Wizard &wiz , Monster &mon , Map guide , char choice)
{
    char action;
    int skillInt = 0;
    int damage = 0;
    int turn = 0;
    Dice chance;
    cout << "As you enter the room, " << mon.getName() << " was waiting for you!" << endl;
    //Different clases have different attacks and skills
    if (choice == 'b')
    {
        while (bar.getHealth() > 0 && mon.getHealth() > 0)
        {
            turn++;
            bar.printCharSheet();
            action = bossFightMenu();
            cout << "---------------------------------------" << endl;
            switch(action)
            {
                //Normal attack
                case 'a':
                {
                    mon.takeDamage(bar.attack(mon.getArmorClass()));
                    break;
                }
                //Special skill, based on class
                case 's':
                {
                    skillInt = bar.skill(mon.getArmorClass());
                    switch(skillInt)
                    {
                        case -1:
                        {
                            fight(bar , rog , wiz , mon , guide , choice);
                            return;
                            break;
                        }
                        case -2:
                        {
                            break;
                        }
                        default:
                        {
                            mon.takeDamage(skillInt);
                            break;
                        }
                    }
                    break;
                }
            }
            //If the palyer died trying to escape or the monster died due to an enemy attack
            if (bar.getHealth() <= 0 || mon.getHealth() <= 0) 
            {
                break;
            }
            if (bar.getTerrifyToggle() == true)
            {
                bar.useTerrify();
                cout << "---------------------------------------" << endl;
                cout << "Congratulations! The " << mon.getName() << " ran away!" << endl;
                bar.untoggleRage();
                int gold = 0;
                gold = (guide.getMapLevel()*chance.dSpecific(200));
                cout << "As the " << mon.getName() << " fled, it dropped " << gold << " gold coins!" << endl;
                bar.changeGold(gold);
                break;
            }
            cout << "---------------------------------------" << endl;
            //Monster attack
            if (guide.getMapLevel() == 1)
            {
                if (turn%3 == 0)
                {
                    cout << "Black oily arms crawl out of the shadows towards you!" << endl;
                    if (chance.d20() > 13)
                    {
                        cout << "The arms scratch and sink into your skill!" << endl;
                        bar.takeDamage(chance.d8() + chance.d8() + chance.d8());
                    }
                    else
                    {
                        cout << "But you manage to get out of their grasp!" << endl;
                    }
                }
                else
                {
                    bar.takeDamage(mon.attack(bar.getArmorClass()));
                }
            }
            if (guide.getMapLevel() == 2)
            {
                if (turn%3 == 0)
                {
                    cout << "Black flames errupt around you!" << endl;
                    if (chance.d20() > 14)
                    {
                        cout << "You're consumed by them!" << endl;
                        bar.takeDamage(chance.d8() + chance.d8() + chance.d8() + chance.d8());
                    }
                    else
                    {
                        cout << "But you manage to put them out before you burn to a crisp!" << endl;
                    }
                }
                else
                {
                    bar.takeDamage(mon.attack(bar.getArmorClass()));
                }
            }
            if (guide.getMapLevel() == 3)
            {
                if (turn%3 == 0)
                {
                    cout << mon.getName() << " opens its cavernous maw and a jet of lava comes in your direction!" << endl;
                    if (chance.d20() > 15)
                    {
                        cout << "The hot magma hits you and it burns your flesh!" << endl;
                        bar.takeDamage(chance.d10() + chance.d10() + chance.d10()+chance.d10());
                    }
                    else
                    {
                        cout << "But you manage to find some cover!" << endl;
                    }
                }
                else
                {
                    bar.takeDamage(mon.attack(bar.getArmorClass()));
                }
            }
        }
        //Player won the fight and now receives gold as reward
        if (bar.getHealth() > 0 && mon.getHealth() <= 0)
        {
            cout << "---------------------------------------" << endl;
            cout << "Congratulations! The " << mon.getName() << " is dead!" << endl;
            bar.untoggleRage();
            int gold = 0;
            gold = (guide.getMapLevel()*chance.dSpecific(200));
            cout << "In the " << mon.getName() << " remains you find " << gold << " gold coins!" << endl;
            bar.changeGold(gold);
        }
    }
    if (choice == 'r')
    {
        while (rog.getHealth() > 0 && mon.getHealth() > 0)
        {
            turn++;
            rog.printCharSheet();
            action = bossFightMenu();
            cout << "---------------------------------------" << endl;
            switch(action)
            {
                //Normal attack
                case 'a':
                {
                    mon.takeDamage(rog.attack(mon.getArmorClass()));
                    break;
                }
                //Special skill, based on class
                case 's':
                {
                    skillInt = rog.skill(mon.getArmorClass());
                    switch(skillInt)
                    {
                        case -1:
                        {
                            fight(bar , rog , wiz , mon , guide , choice);
                            return;
                            break;
                        }
                        case -2:
                        {
                            break;
                        }
                        default:
                        {
                            mon.takeDamage(skillInt);
                            break;
                        }
                    }
                    break;
                }
            }
            //If the palyer died trying to escape or the monster died due to an enemy attack
            if (rog.getHealth() <= 0 || mon.getHealth() <= 0) 
            {
                break;
            }
            cout << "---------------------------------------" << endl;
            //Monster attack
            if (guide.getMapLevel() == 1)
            {
                if (turn%3 == 0)
                {
                    cout << "Black oily arms crawl out of the shadows towards you!" << endl;
                    if (chance.d20() > 13)
                    {
                        cout << "The arms scratch and sink into your skill!" << endl;
                        rog.takeDamage(chance.d8() + chance.d8() + chance.d8());
                    }
                    else
                    {
                        cout << "But you manage to get out of their grasp!" << endl;
                    }
                }
                else
                {
                    rog.takeDamage(mon.attack(bar.getArmorClass()));
                }
            }
            if (guide.getMapLevel() == 2)
            {
                if (turn%3 == 0)
                {
                    cout << "Black flames errupt around you!" << endl;
                    if (chance.d20() > 14)
                    {
                        cout << "You're consumed by them!" << endl;
                        rog.takeDamage(chance.d8() + chance.d8() + chance.d8() + chance.d8());
                    }
                    else
                    {
                        cout << "But you manage to put them out before you burn to a crisp!" << endl;
                    }
                }
                else
                {
                    rog.takeDamage(mon.attack(bar.getArmorClass()));
                }
            }
            if (guide.getMapLevel() == 3)
            {
                if (turn%3 == 0)
                {
                    cout << mon.getName() << " opens its cavernous maw and a jet of lava comes in your direction!" << endl;
                    if (chance.d20() > 15)
                    {
                        cout << "The hot magma hits you and it burns your flesh!" << endl;
                        rog.takeDamage(chance.d10() + chance.d10() + chance.d10()+chance.d10());
                    }
                    else
                    {
                        cout << "But you manage to find some cover!" << endl;
                    }
                }
                else
                {
                    rog.takeDamage(mon.attack(bar.getArmorClass()));
                }
            }
        }
        //Player won the fight and now receives gold as reward
        if (rog.getHealth() > 0 && mon.getHealth() <= 0)
        {
            cout << "---------------------------------------" << endl;
            cout << "Congratulations! The " << mon.getName() << " is dead!" << endl;
            if (rog.getPoisonActive() == true)
            {
                rog.setPoisonActive();
            }
            int gold = 0;
            gold = (guide.getMapLevel()*chance.dSpecific(200));
            cout << "In the " << mon.getName() << " remains you find " << gold << " gold coins!" << endl;
            rog.changeGold(gold);
        }
    }
    if (choice == 'w')
    {
        while (wiz.getHealth() > 0 && mon.getHealth() > 0)
        {
            turn++;
            wiz.printCharSheet();
            action = bossFightMenu();
            
            switch(action)
            {
                //Normal attack
                case 'a':
                {
                    cout << "---------------------------------------" << endl;
                    mon.takeDamage(wiz.attack(mon.getArmorClass()));
                    break;
                }
                //Special skill, based on class
                case 's':
                {
                    skillInt = wiz.skill(mon.getArmorClass());
                    switch(skillInt)
                    {
                        case -1:
                        {
                            fight(bar , rog , wiz , mon , guide , choice);
                            return;
                            break;
                        }
                        case -2:
                        {
                            break;
                        }
                        default:
                        {
                            mon.takeDamage(skillInt);
                            break;
                        }
                    }
                    break;
                }
            }
            //If the palyer died trying to escape or the monster died due to an enemy attack
            if (wiz.getHealth() <= 0 || mon.getHealth() <= 0) 
            {
                break;
            }
            cout << "---------------------------------------" << endl;
            //Monster attack
            if (guide.getMapLevel() == 1)
            {
                if (turn%3 == 0)
                {
                    cout << "Black oily arms crawl out of the shadows towards you!" << endl;
                    if (chance.d20() > 13)
                    {
                        cout << "The arms scratch and sink into your skill!" << endl;
                        wiz.takeDamage(chance.d8() + chance.d8() + chance.d8());
                    }
                    else
                    {
                        cout << "But you manage to get out of their grasp!" << endl;
                    }
                }
                else
                {
                    wiz.takeDamage(mon.attack(bar.getArmorClass()));
                }
            }
            if (guide.getMapLevel() == 2)
            {
                if (turn%3 == 0)
                {
                    cout << "Black flames errupt around you!" << endl;
                    if (chance.d20() > 14)
                    {
                        cout << "You're consumed by them!" << endl;
                        wiz.takeDamage(chance.d8() + chance.d8() + chance.d8() + chance.d8());
                    }
                    else
                    {
                        cout << "But you manage to put them out before you burn to a crisp!" << endl;
                    }
                }
                else
                {
                    wiz.takeDamage(mon.attack(bar.getArmorClass()));
                }
            }
            if (guide.getMapLevel() == 3)
            {
                if (turn%3 == 0)
                {
                    cout << mon.getName() << " opens its cavernous maw and a jet of lava comes in your direction!" << endl;
                    if (chance.d20() > 15)
                    {
                        cout << "The hot magma hits you and it burns your flesh!" << endl;
                        wiz.takeDamage(chance.d10() + chance.d10() + chance.d10()+chance.d10());
                    }
                    else
                    {
                        cout << "But you manage to find some cover!" << endl;
                    }
                }
                else
                {
                    wiz.takeDamage(mon.attack(bar.getArmorClass()));
                }
            }
        }
        //Player won the fight and now receives gold as reward
        if (wiz.getHealth() > 0 && mon.getHealth() <= 0)
        {
            cout << "---------------------------------------" << endl;
            cout << "Congratulations! The " << mon.getName() << " is dead!" << endl;
            wiz.setArmorClass(10+wiz.getLevel());
            int gold = 0;
            gold = (guide.getMapLevel()*chance.dSpecific(200));
            cout << "In the " << mon.getName() << " remains you find " << gold << " gold coins!" << endl;
            wiz.changeGold(gold);
        }
    }
}


//Allows the player to move once, move continuously or save and quit the game
int mainMenu(Barbarian &bar, Rogue &rog , Wizard &wiz , Monster &mon , Map &guide , int fightCounter , char choice)
{
    string sOut;
    char out;
    cout << "---------------------------------------" << endl;
    if (choice == 'b')
    {
        bar.printCharSheet();
    }
    if (choice == 'r')
    {
        rog.printCharSheet();
    }
    if (choice == 'w')
    {
        wiz.printCharSheet();
    }
    while (true)
    {
        cout << "---------------------------------------" << endl;
        cout << "What's would you like to do?" << endl;
        cout << "m - Move" << endl;
        cout << "c - Continuous Movement" << endl;
        cout << "s - Save and Quit" << endl;
        cout << "---------------------------------------" << endl;
        getline(cin,sOut);
        out = sOut[0];
        if (out == 'm' || out == 'M' || out == 'c' || out == 'C' || out == 's' || out == 'S')
        {
            out = tolower(out);
            break;
        }
        cout << "Invalid option. Please enter a valid option." << endl;
    }
    bool boolFight = false;
    switch (out)
    {
        //Player will move only one space
        case 'm':
        {
            guide.move();
            fightCounter++;
            return fightCounter;
            break;
        }
        //Player will move indefinetly, until fightCheck return true, they reach a boss fight or they descend a level
        case 'c':
        {
            while(true)
            {
                guide.move();
                fightCounter++;
                //Checking for level changed
                if (choice == 'b')
                {
                    if (guide.getMapLevel() != bar.getLevel())
                    {
                        return fightCounter;
                    }
                }
                if (choice == 'r')
                {
                    if (guide.getMapLevel() != rog.getLevel())
                    {
                        return fightCounter;
                    }
                }
                if (choice == 'w')
                {
                    if (guide.getMapLevel() != wiz.getLevel())
                    {
                        return fightCounter;
                    }
                }
                //Cheking for a boss fight location trigger
                if (guide.getMapLevel() == 1 && guide.getLocationY() == 4 && guide.getLocationX() == 6)
                {
                    return -5;
                }
                if (guide.getMapLevel() == 2 && guide.getLocationY() == 14 && guide.getLocationX() == 6)
                {
                    return -5;
                }
                if (guide.getMapLevel() == 3 && guide.getLocationY() == 4 && guide.getLocationX() == 6)
                {
                    return -5;
                }
                if (guide.getMapLevel() == 3 && guide.getLocationX() == 1 && guide.getLocationY() > 0 && guide.getLocationY() < 7)
                {
                    return -5;
                }
                boolFight = fightCheck(fightCounter);
                if (boolFight == true)
                {
                    monsterRand(mon , guide);
                    fight(bar , rog , wiz , mon , guide , choice);
                    return -5;
                }
            }
            break;
        }
        //Saves and quits the game
        case 's':
        {
            string heroName;
            if (choice == 'b')
            {
                heroName = bar.getName();
            }
            if (choice == 'r')
            {
                heroName = rog.getName();
            }
            if (choice == 'w')
            {
                heroName = wiz.getName();
            }
            fstream inFile;
            inFile.open("dungeonLoad.txt");
            if (inFile.fail())
            {
                cout << "Missing dungeonLoad.txt" << endl;
                exit(0);
            }
            string line;
            string currentLine[16];
            vector<string> saves;
            //Adds all the information of other characters
            while(getline(inFile,line))
            {
                if (line != "")
                {
                    split(line , ',' , currentLine);
                    if (currentLine[0] != heroName)
                    {
                        saves.push_back(line);
                    }
                }
            }
            inFile.close();
            ofstream ofFile;
            ofFile.open("dungeonLoad.txt");
            if (ofFile.fail())
            {
                cout << "Error with ofFile" << endl;
                exit(0);
            }
            //Writes the other characters (overwrites what was in the file before)
            for (int i = 0 ; i < saves.size() ; i++)
            {
                ofFile << saves[i] << "\n";
            }
            ofFile.close();
            ofstream file;
            file.open("dungeonLoad.txt" , ofstream::app);
            //Appends the information of the current player into dungeonLoad.txt depending on their class and then shows their score relative to the other characters
            if (choice == 'b')
            {
                file << bar.getName() << "," << to_string(bar.getHealth()) << "," << to_string(bar.getGold()) << "," << choice << "," << to_string(bar.getLevel()) << "," << to_string(bar.getRageCount()) << "," << to_string(bar.getTerrifyCount()) << "," << to_string(bar.getRecklessCount()) << ",0,0,0,0,0,alive," << to_string(guide.getLocationY()) << "," << to_string(guide.getLocationX()) << "\n";
                file.close();
                cout << "Game saved" << endl;
                cout << "The Dungeon awaits you with many perrils! Thank you for playing!" << endl;
                wallOfAdventurers();
                exit(0);
            }
            if (choice == 'r')
            {
                file << rog.getName() << "," << to_string(rog.getHealth()) << "," << to_string(rog.getGold()) << "," << choice << "," << to_string(rog.getLevel()) << ",0,0,0," << to_string(rog.getAssassinate()) << "," << to_string(rog.getPoison()) << ",0,0,0,alive," << to_string(guide.getLocationY()) << "," << to_string(guide.getLocationX()) << "\n";
                file.close();
                cout << "Game saved" << endl;
                cout << "The Dungeon awaits you with many perrils! Thank you for playing!" << endl;
                wallOfAdventurers();
                exit(0);
            }
            if (choice == 'w')
            {
                file << wiz.getName() << "," << to_string(wiz.getHealth()) << "," << to_string(wiz.getGold()) << "," << choice << "," << to_string(wiz.getLevel()) << ",0,0,0,0,0," << to_string(wiz.getFireball()) << "," << to_string(wiz.getMagicMissile()) << "," << to_string(wiz.getMageArmor()) << ",alive," << to_string(guide.getLocationY()) << "," << to_string(guide.getLocationX()) << "\n";
                file.close();
                cout << "Game saved" << endl;
                cout << "The Dungeon awaits you with many perrils! Thank you for playing!" << endl;
                wallOfAdventurers();
                exit(0);
            }
            break;
        }
        //Will never occur
        default:
        {
            break;
        }
    }
}

//Main function
//Keeps calling the funcions until player saves and quits our dies
int main()
{
    cout << "                            ~~~~~~~~ THE DUNGEON ~~~~~~~~" << endl;
    cout << "Welcome to The Dungeon adventurer! This is text-based dungeon crawl game!" << endl;
    cout << "Here your objective is to survive The Dungeon while figthing mosters, bosses and collecting gold!" << endl;
    Barbarian bar;
    Rogue rog;
    Wizard wiz;
    Monster mon;
    Map guide;
    char choice;
    bool boolFight;
    int fightCounter = -3;
    choice = createChar(bar , rog , wiz , guide);
    while (bar.getHealth() > 0 && rog.getHealth() > 0 && wiz.getHealth() > 0)
    {
        fightCounter = mainMenu(bar , rog , wiz , mon , guide , fightCounter , choice);
        if (choice == 'b')
        {
            if (guide.getMapLevel() != bar.getLevel())
            {
                bar.levelUp();
            }
        }
        if (choice == 'r')
        {
            if (guide.getMapLevel() != rog.getLevel())
            {
                rog.levelUp();
            }
        }
        if (choice == 'w')
        {
            if (guide.getMapLevel() != wiz.getLevel())
            {
                wiz.levelUp();
            }
        }
        //Cheking for a boss fight location trigger
        if (guide.getMapLevel() == 1 && guide.getLocationY() == 4 && guide.getLocationX() == 6)
        {
            bossRand(mon , guide);
            bossFight(bar , rog , wiz , mon , guide , choice);
            fightCounter = -5;
        }
        if (guide.getMapLevel() == 2 && guide.getLocationY() == 14 && guide.getLocationX() == 6)
        {
            bossRand(mon , guide);
            bossFight(bar , rog , wiz , mon , guide , choice);
            fightCounter = -5;
        }
        if (guide.getMapLevel() == 3 && guide.getLocationY() == 4 && guide.getLocationX() == 6)
        {
            bossRand(mon , guide);
            bossFight(bar , rog , wiz , mon , guide , choice);
            fightCounter = -5;
        }
        if (guide.getMapLevel() == 3 && guide.getLocationX() == 1 && guide.getLocationY() > 0 && guide.getLocationY() < 7)
        {
            cout << "You found the hoard of Brandrax'Il!" << endl;
            cout << "As you count your tresure you find 10000 gold coins!" << endl;
            cout << "When you go back to town you become a legend forever in the minds of the townsfolk!" << endl;
            if (choice == 'b')
            {
                bar.changeGold(10000);
            }
            if (choice == 'r')
            {
                rog.changeGold(10000);
            }
            if (choice == 'w')
            {
                wiz.changeGold(10000);
            }
            break;
        }
        //Checking for fight trigger
        boolFight = fightCheck(fightCounter);
        if (boolFight == true)
        {
            monsterRand(mon , guide);
            fight(bar , rog , wiz , mon , guide , choice);
            fightCounter = -5;
        }
    }
    if (bar.getHealth() <= 0 || rog.getHealth() <= 0 || wiz.getHealth() <= 0)
    {
        cout << "The Dungeon was too much for you!" << endl;
        cout << "However, your death inspired many others heros to come and explore The Dungeon!" << endl;
    }
    //This means the player died, or finished The Dungeon
    string heroName;
    if (choice == 'b')
    {
        heroName = bar.getName();
    }
    if (choice == 'r')
    {
        heroName = rog.getName();
    }
    if (choice == 'w')
    {
        heroName = wiz.getName();
    }
    fstream inFile;
    inFile.open("dungeonLoad.txt");
    if (inFile.fail())
    {
        cout << "Missing dungeonLoad.txt" << endl;
        exit(0);
    }
    string line;
    string currentLine[16];
    vector<string> saves;
    //Adds all the information of other characters
    while(getline(inFile,line))
    {
        if (line != "")
        {
            split(line , ',' , currentLine);
            if (currentLine[0] != heroName)
            {
                saves.push_back(line);
            }
        }
    }
    inFile.close();
    ofstream ofFile;
    ofFile.open("dungeonLoad.txt");
    if (ofFile.fail())
    {
        cout << "Error with ofFile" << endl;
        exit(0);
    }
    //Writes the other characters (overwrites what was in the file before)
    for (int i = 0 ; i < saves.size() ; i++)
    {
        ofFile << saves[i] << "\n";
    }
    ofFile.close();
    ofstream file;
    file.open("dungeonLoad.txt" , ofstream::app);
    //Appends the information of the current player into dungeonLoad.txt depending on their class and then shows their score relative to the other characters
    if (choice == 'b')
    {
        file << bar.getName() << "," << to_string(bar.getHealth()) << "," << to_string(bar.getGold()) << "," << choice << "," << to_string(bar.getLevel()) << "," << to_string(bar.getRageCount()) << "," << to_string(bar.getTerrifyCount()) << "," << to_string(bar.getRecklessCount()) << ",0,0,0,0,0,dead," << to_string(guide.getLocationY()) << "," << to_string(guide.getLocationX()) << "\n";
        file.close();
        cout << "Game saved" << endl;
        cout << "The Dungeon awaits you with many perrils! Thank you for playing!" << endl;
        wallOfAdventurers();
        exit(0);
    }
    if (choice == 'r')
    {
        file << rog.getName() << "," << to_string(rog.getHealth()) << "," << to_string(rog.getGold()) << "," << choice << "," << to_string(rog.getLevel()) << ",0,0,0," << to_string(rog.getAssassinate()) << "," << to_string(rog.getPoison()) << ",0,0,0,dead," << to_string(guide.getLocationY()) << "," << to_string(guide.getLocationX()) << "\n";
        file.close();
        cout << "Game saved" << endl;
        cout << "The Dungeon awaits you with many perrils! Thank you for playing!" << endl;
        wallOfAdventurers();
        exit(0);
    }
    if (choice == 'w')
    {
        file << wiz.getName() << "," << to_string(wiz.getHealth()) << "," << to_string(wiz.getGold()) << "," << choice << "," << to_string(wiz.getLevel()) << ",0,0,0,0,0," << to_string(wiz.getFireball()) << "," << to_string(wiz.getMagicMissile()) << "," << to_string(wiz.getMageArmor()) << ",dead," << to_string(guide.getLocationY()) << "," << to_string(guide.getLocationX()) << "\n";
        file.close();
        cout << "Game saved" << endl;
        cout << "The Dungeon awaits you with many perrils! Thank you for playing!" << endl;
        wallOfAdventurers();
        exit(0);
    }
}