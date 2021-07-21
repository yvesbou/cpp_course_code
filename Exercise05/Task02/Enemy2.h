
#ifndef EXERCISE05_ENEMY2_H
#define EXERCISE05_ENEMY2_H


#include <iostream>
#include <string>
#include <stdlib.h>


namespace ch::uzh::frauchiger::dominik::l4
{
    template <typename F>
    struct player_frauchi
    {
        // returns the column where the player decides to insert his
        // stone
        // F is the playfield which may be any playfield implementing
        // the stoneat method, if you expect a different class because
        // you need methods to verify whether the opponent can win,
        // copy the field into the class that you expect.
        int play(const F &field)
        {
            //std::cout << "me " << me << std::endl;
            //std::cout << "last " << last << std::endl;

            if (me == 0)
            {
                me = 1;
                for (int i = 0; i < field.width; ++i)
                {
                    if (field.stoneat(i, field.height - 1) != 0)
                    {
                        me = 2;
                    }
                }
                //std::cout << "I am player " << (int)me << std::endl;
                last = rand() % field.width;
                //std::cout << "First placement (random) " << last << std::endl;
                return last;
            }

            int h = field.height - 1;

            // top
            //std::cout << "Checking top" << std::endl;
            while (field.stoneat(last, h) == me && h >= 0)
            {
                --h;
            }
            //std::cout << "Try on " << last << " " << h << std::endl;
            if (h >= 0 && field.stoneat(last, h) == 0)
            {
                //std::cout << "Placing top " << last << std::endl;
                return last;
            }

            // right
            //std::cout << "Checking right" << std::endl;
            if (last < field.width - 1)
            {
                while (field.stoneat(last + 1, h) == me && h >= 0)
                {
                    --h;
                }
                //std::cout << "Try on " << last << " " << h << std::endl;
                if (h >= 0 && field.stoneat(last + 1, h) == 0)
                {
                    last += 1;
                    //std::cout << "Placing right " << last << std::endl;
                    return last;
                }
            }
            else
            {
                //std::cout << "Out of field" << std::endl;
            }

            // left
            //std::cout << "Checking left" << std::endl;
            if (last > 0)
            {
                while (field.stoneat(last - 1, h) == me && h >= 0)
                {
                    --h;
                }
                //std::cout << "Try on " << last << " " << h << std::endl;
                if (h >= 0 && field.stoneat(last - 1, h) == 0)
                {
                    last -= 1;
                    //std::cout << "Placing left " << last << std::endl;
                    return last;
                }
            }
            else
            {
                //std::cout << "Out of field" << std::endl;
            }

            // random placement
            while (1)
            {
                last = rand() % field.width;
                if (field.stoneat(last, 0) == 0)
                    break;
            }
            //std::cout << "Placing randomly " << last << std::endl;
            return last;
        }
        // end provided

        player_frauchi() : name("Bot"), me(0), last(0){
            //std::cout << "Bot created" << std::endl;
        };
        player_frauchi(std::string name) : name(name), me(0), last(0){};

        void Win()
        {
            std::cout << "Congratulations! " << name << ", you won!" << std::endl;
        }

    private:
        std::string name;
        int me;
        int last;
    };
} // namespace ch::uzh::frauchiger::dominik::l4


#endif //EXERCISE05_ENEMY2_H
