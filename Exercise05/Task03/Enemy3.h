#pragma once
#include <algorithm>
template <typename F>
class computerplayer{
private:
    int p;
    char board[7][6];

    bool playable(int row, char board[7][6])
    {
        return (board[row][0] == 0);
    };

    int getheight(int row, char board[7][6])
    {
        for (int i = 0; i < 6; i++)
        {
            if (board[row][i] != 0)
            {
                return i - 1;
            }
        }
        return 5;
    };

    int calculatescoreforrow(int me, int none)
    {
        if (me == 4)
        {
            return 20000;
        }
        else if (me == 3 && none == 1)
        {
            return 20;
        }
        else if (me == 2 && none == 2)
        {
            return 3;
        }
        else if (me == 2 && none == 1)
        {
            return 2;
        }
        else if (me == 2 && none == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int scoremiddleline(char board[7][6], int player) {
        int score = 0;
        for (int i = 0; i < 6; i++) {
            score += board[3][i] == player ? 7 : 0;
        }
        return score;
    }

    int scorevertical(char board[7][6], int player)
    {
        int score = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                int count[3] = { 0, 0, 0 };
                count[board[j][i]] += 1;
                count[board[j][i + 1]] += 1;
                count[board[j][i + 2]] += 1;
                count[board[j][i + 3]] += 1;
                score += calculatescoreforrow(count[player], count[0]);
            }
        }
        return score;
    }

    int scorehorizontal(char board[7][6], int player)
    {
        int score = 0;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int count[3] = { 0, 0, 0 };
                count[board[j][i]] += 1;
                count[board[j + 1][i]] += 1;
                count[board[j + 2][i]] += 1;
                count[board[j + 3][i]] += 1;
                score += calculatescoreforrow(count[player], count[0]);
            }
        }
        return score;
    }

    int scorediagonal(char board[7][6], int player)
    {
        int score = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int count[3] = { 0, 0, 0 };
                count[board[j][i]] += 1;
                count[board[j + 1][i + 1]] += 1;
                count[board[j + 2][i + 2]] += 1;
                count[board[j + 3][i + 3]] += 1;
                score += calculatescoreforrow(count[player], count[0]);
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 6; j >= 3; j--)
            {
                int count[3] = { 0, 0, 0 };
                count[board[j][i]] += 1;
                count[board[j - 1][i + 1]] += 1;
                count[board[j - 2][i + 2]] += 1;
                count[board[j - 3][i + 3]] += 1;
                score += calculatescoreforrow(count[player], count[0]);
            }
        }
        return score;
    }

    int scoreofboard(char board[7][6], int player)
    {
        int opponent = player == 1 ? 2 : 1;
        int myscore = scorehorizontal(board, player) + scorevertical(board, player) + scorediagonal(board, player) + scoremiddleline(board, player);
        int scoreopponent = scorehorizontal(board, opponent) + scorevertical(board, opponent) + scorediagonal(board, opponent) + scoremiddleline(board, opponent);
        return myscore - opponent;
    }

    int minmax(char board[7][6], int depth, char currentplayer, char opponent, char me, int alpha, int beta)
    {
        int score = scoreofboard(board, currentplayer);
        if (score >= 10000 || depth == 0)
        {
            return currentplayer == me ? score * (depth + 1) : (-score) * (depth + 1);
        }
        if (currentplayer == me)
        {
            int maxvalue = -9999999;
            for (int i = 3, j = 1; i != 7; i += j, j = j < 0 ? (j - 1) * (-1) : (j + 1) * (-1))
            {
                if (playable(i, board))
                {
                    int height = getheight(i, board);
                    board[i][height] = currentplayer;
                    int eval = minmax(board, depth - 1, opponent, opponent, me, alpha, beta);
                    board[i][height] = 0;
                    maxvalue = std::max(maxvalue, eval);
                    alpha = std::max(alpha, eval);
                    if (beta <= alpha)
                    {
                        break;
                    }
                }
            }
            return maxvalue;
        }
        else
        {
            int minvalue = 9999999;
            for (int i = 3, j = 1; i != 7; i += j, j = j < 0 ? (j - 1) * (-1) : (j + 1) * (-1))
            {
                if (playable(i, board))
                {
                    int height = getheight(i, board);
                    board[i][height] = currentplayer;
                    int eval = minmax(board, depth - 1, me, opponent, me, alpha, beta);
                    board[i][height] = 0;
                    minvalue = std::min(minvalue, eval);
                    beta = std::min(beta, eval);
                    if (beta <= alpha)
                    {
                        break;
                    }
                }
            }
            return minvalue;
        }
        return 0;
    }

    int startminmax()
    {
        int alpha = -5000000;
        int beta = 50000000;
        int results[7];
        for (int i = 3, j = 1; i != 7; i += j, j = j < 0 ? (j - 1) * (-1) : (j + 1) * (-1))
        {
            results[i] = -99999999;
            if (playable(i, board))
            {
                int height = getheight(i, board);
                board[i][height] = p;
                results[i] = minmax(board, 9, p == 1 ? 2 : 1, p == 1 ? 2 : 1, p, alpha, beta);
                board[i][height] = 0;
            }
        }

        int maxresult = results[3];
        int toplay = 3;
        for (int i = 3, j = 1; i != 7; i += j, j = j < 0 ? (j - 1) * (-1) : (j + 1) * (-1))
        {
            if (results[i] > maxresult)
            {
                toplay = i;
                maxresult = results[i];
            }
        }
        return toplay;
    }

public:
    computerplayer(int player) : p(player) {
    }
    ~computerplayer() {
        delete[] &board;
    }

    int play(const F& field)
    {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                board[i][j] = field.stoneat(i, j);
            }
        }
        return startminmax();
    };
};