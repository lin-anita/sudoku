#include <iostream>
#include <windows.h>
#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */

using namespace std;

int a1[9][9] = {
{1, 0, 2, 0, 0, 0, 9, 0, 0},  
{0, 3, 0, 0, 0, 6, 4, 0, 2},  
{0, 6, 0, 0, 8, 0, 0, 3, 0},  
{0, 1, 4, 0, 0, 2, 0, 0, 5},  
{2, 0, 0, 0, 3, 1, 0, 0, 0},  
{0, 0, 3, 9, 0, 0, 0, 0, 0},  
{0, 0, 0, 5, 0, 0, 8, 1, 0},  
{0, 5, 0, 0, 6, 0, 0, 0, 9},  
{0, 0, 0, 3, 1, 0, 6, 5, 7}
};

int a2[9][9] = {
{0, 9, 0, 0, 7, 0, 0, 0, 6},  
{0, 5, 0, 0, 9, 3, 0, 8, 0},  
{3, 0, 0, 0, 8, 4, 9, 0, 2},  
{4, 0, 2, 0, 0, 0, 0, 0, 0},  
{0, 0, 0, 0, 0, 6, 0, 0, 0},  
{0, 3, 0, 7, 0, 0, 1, 0, 0},  
{1, 0, 0, 0, 0, 2, 4, 9, 3},  
{0, 2, 0, 0, 1, 0, 0, 0, 5},  
{6, 0, 0, 9, 3, 0, 0, 0, 7} 
};

int a3[9][9] = {
{6, 4, 8, 0, 0, 9, 0, 0, 0},  
{2, 0, 9, 8, 0, 0, 1, 0, 0},  
{3, 0, 0, 0, 0, 0, 0, 0, 0},  
{7, 0, 0, 0, 8, 6, 4, 0, 9},  
{0, 0, 0, 0, 2, 0, 3, 0, 0},  
{0, 9, 0, 3, 0, 1, 0, 8, 6},  
{0, 0, 0, 0, 5, 0, 0, 4, 0},  
{0, 0, 3, 1, 0, 0, 0, 0, 2},  
{0, 6, 1, 0, 0, 8, 7, 0, 0} 

};

int a11[9][9]={
{1, 8, 2, 4, 5, 3, 9, 7, 6},
{5, 3, 7, 1, 9, 6, 4, 8, 2},
{4, 6, 9, 2, 8, 7, 5, 3, 1},
{8, 1, 4, 6, 7, 2, 3, 9, 5},
{2, 9, 5, 8, 3, 1, 7, 6, 4},
{6, 7, 3, 9, 4, 5, 1, 2, 8},
{7, 4, 6, 5, 2, 9, 8, 1, 3},
{3, 5, 1, 7, 6, 8, 2, 4, 9},
{9, 2, 8, 3, 1, 4, 6, 5, 7}
};

int a22[9][9]={
{8, 9, 1, 2, 7, 5, 3, 4, 6},  
{4, 5, 7, 6, 9, 3, 2, 8, 1},  
{3, 6, 2, 1, 8, 4, 9, 7, 5},  
{4, 7, 2, 5, 6, 9, 8, 1, 3},  
{5, 8, 9, 3, 4, 6, 7, 2, 1},  
{2, 3, 6, 7, 1, 8, 1, 5, 4},  
{1, 4, 5, 8, 2, 7, 4, 9, 3},  
{7, 2, 3, 4, 1, 9, 6, 3, 5},  
{6, 1, 8, 9, 3, 2, 5, 1, 7}  

};

int a33[9][9] = {
{6, 4, 8, 7, 1, 9, 5, 2, 3},  
{2, 7, 9, 8, 3, 5, 1, 6, 4},  
{3, 1, 5, 4, 6, 2, 9, 7, 8},  
{7, 3, 2, 5, 8, 4, 6, 9, 1},  
{4, 8, 6, 9, 7, 1, 2, 3, 5},  
{5, 9, 1, 6, 2, 3, 4, 8, 7},  
{8, 2, 3, 1, 9, 7, 7, 5, 6},  
{9, 6, 4, 2, 5, 8, 3, 1, 7},  
{1, 5, 7, 3, 4, 6, 8, 9, 2}
};

void show_ans(int board_num)
{
	for(int i = 0; i < 9; i++)
	{
        	for(int j = 0; j < 9; j++) 
			{
            	switch(board_num) 
				{
                	case 1:
                		cout <<a11[i][j]<<" ";
                    	break;
                	case 2:
                		cout <<a22[i][j]<<" ";
                    	break;
                	case 3:
                		cout <<a33[i][j]<<" ";
                    	break;
           		}
        	}
    	cout <<endl;
	}
}

bool editable[9][9];
int board2[9][9],board[9][9];

int cur_r = 0, cur_c = 0;

bool check_horizontal()
{
    /* TODO: Check if a horizontal line has conflict number, or is finished. */
    bool nums[10] = {false};  // 只檢查目前光標所在行
    for (int j = 0; j < 9; ++j) {
        int num = board2[cur_r][j];
        if (num > 0) {
            if (nums[num]) {
                return true;  // 有衝突
            }
            nums[num] = true;//記錄看過的數字 
        }
    }
    return false;  // 沒有衝突
}

bool check_vertical()
{
    /* TODO: Check if a vertical line has conflict number, or is finished. */
    bool nums[10] = {false};  // 只檢查目前光標所在行
    for (int j = 0; j < 9; ++j) {
        int num = board2[j][cur_c];
        if (num > 0) {
            if (nums[num]) {
                return true;  // 有衝突
            }
            nums[num] = true;//記錄看過的數字 
        }
    }
    return false;  // 沒有衝突
}

bool check_block()
{
    /* TODO: Check if a block has conflict number, or is finished. */
    int a,b;
    //開始在每大格的左上小格 
    a=cur_r/3*3;
	b=cur_c/3*3;
	
	bool nums[10]={false};
	
	for(int t=a;t<a+3;t++){
		for(int g=b;g<b+3;g++)
		{
			int num = board2[t][g];
        	if (num > 0) 
			{
            	if (nums[num]) 
				{
                	return true;  // 有衝突
            	}
            nums[num] = true;//記錄看過的數字 
        	}
		}
    }
    return false;
}

void fill_number(char c)
{
    /* TODO: Fill a number in to the cell the cursor is now pointing to.
             After fill in the number, check the horizontal line, the
             vertical line and the block the cell is in.
     */
    /*檢查是否衝突放在print_board裡面*/
	// 包含 0 的情況
	if (editable[cur_r][cur_c]){
		if (c >= '0' && c <= '9') {  
        board2[cur_r][cur_c] = c - '0';
   		}
	}
    else return;
}

void move_cursor(char c)
{
    /* TODO: Move the cursor up, down, to the left or to the right.
             Remember to check if the cursor is moving out of bound.
    */
    int original_r = cur_r, original_c = cur_c;
    
    switch (toupper(c)) {//變大寫 
        case 'W':
            if (cur_r > 0) cur_r--;//(防超出遊戲框)；光標往上 
            break;
        case 'S':
            if (cur_r < 8) cur_r++;//(防超出遊戲框)；光標往下 
            break;
        case 'A':
            if (cur_c > 0) cur_c--;//(防超出遊戲框)；光標往左 
            break;
        case 'D':
            if (cur_c < 8) cur_c++;//(防超出遊戲框)；光標往右 
            break;
    }
}

bool is_invalid(int i, int j)
{
    /* TODO: Check if board[i][j] is in a line that has conflict numbers. */
    int save_r,save_c;
    
    save_r=cur_r;
    save_c=cur_c;
    
    cur_r=i;
    cur_c=j;
    
    bool invalid;
    invalid=check_horizontal() || check_vertical() || check_block();
    
    cur_r=save_r;
    cur_c=save_c;
    
    return invalid;
}

bool is_done(int i, int j)
{
    /* TODO: Check if board[i][j] is in a line that has finished. */
    bool b1=true,b2=true,b3=true;
    int save_r,save_c;
    
    save_r=cur_r;
    save_c=cur_c;
    
    cur_r=i;
    cur_c=j;
    
    if (check_horizontal() || check_vertical() || check_block()) {
        cur_r = save_r;
        cur_c = save_c;
        return false;
    }

    
    //列有沒有填滿
	for(int f=0;f<9;f++){
		if(!board2[f][j])
		{
			cur_r=save_r;
    		cur_c=save_c;
			b1= false;
			break;
		} 
	} 
	
	//行有沒有填滿
	for(int f=0;f<9;f++){
		if(!board2[i][f])
		{
			cur_r=save_r;
    		cur_c=save_c;
			b2= false;
			break;
		}
	}
	
	//block有沒有填滿
	int x,y;
    //開始在每大格的左上小格 
    x=(i/3)*3;
	y=(j/3)*3;
	
	for(int t=x;t<x+3;t++){
		for(int g=y;g<y+3;g++)
		{
			if(!board2[t][g]) 
			{
				cur_r=save_r;
    			cur_c=save_c;
				b3= false;
				break;
			}
			if(!b3) break;
		}
		
    }
    
    cur_r=save_r;
    cur_c=save_c;
    
    return b1||b2||b3 ;
}

bool check_win()
{
    /* TODO: Check if the game is set. That is, every cell is finished. */
    // 檢查所有格子是否都填滿
/**/    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board2[i][j] == 0) {
                return false;
            }
        }
    }
    
    // 檢查是否有任何衝突
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(is_invalid(i, j)) {
                return false;
            }
        }
    }
    
    return true;  // 全部填滿且沒有衝突
}

bool is_moving_action(char c)
{
    return (c == 'W' || c == 'w' || c == 'S' || c == 's' ||
            c == 'A' || c == 'a' || c == 'D' || c == 'd');
}

bool is_filling_action(char c)
{
    return (c >= '0' && c <= '9');
}

string get_styled_text(string text, string style)
{
    string color = "", font = "";
    for (char c : style)
    {
        if (c == 'R')
            color = "31";
        if (c == 'G')
            color = "32";
        if (c == 'E')
            color = "41";
        if (c == 'C')
            color = "106";
        if (c == 'B')
            font = ";1";
    }
    return "\x1b[" + color + font + "m" + text + "\x1b[0m";
}

void print_board(int count)
{
    // Flush the screen
    cout << "\x1b[2J\x1b[1;1H";

    // Print usage hint.
    cout << get_styled_text("W/A/S/D: ", "B") << "move cursor" << endl;
    cout << get_styled_text("    1-4: ", "B") << "fill in number" << endl;
    cout << get_styled_text("      0: ", "B") << "clear the cell" << endl;
    cout << get_styled_text("      Q: ", "B") << "quit" << endl;
    cout << get_styled_text("      H: ", "B") << "answer" << endl;
    cout << endl;

    // Iterate through and print each cell.
    for (int i = 0; i < 9; ++i)
    {
        // Print horizontal divider.
        if (i && i % 3 == 0)
            cout << "------------------------------" << endl;

        // Print the first vertical divider in each line.
        cout << "|";
        for (int j = 0; j < 9; ++j)
        {
            // Set text style based on the state of the cell.
            string style = "";

            // Set style for the cell the cursor pointing to.
            if (cur_r == i && cur_c == j)
                style = "C";
            // Set style for the cell in an invalid line.
            else if (is_invalid(i, j))
                style = "E";
            // Set style for the cell in a finished line.
            else if (is_done(i, j))
                style = "G";

            // Set style for a the cell that is immutable.
            if (!editable[i][j])
                style += "B";

            // Print the cell out in styled text.
            // If the content is 0, print a dot, else print the number.
            
            if (count == 1) {
            // 使用原始題目 (board)
            	if (board[i][j] == 0)
            		cout << get_styled_text(" · ", style);
            	else
            		cout << get_styled_text(" " + to_string(board[i][j]) + " ", style);
            	}
			else {
			// 使用遊戲狀態 (board2)
			if (board2[i][j] == 0)
			cout << get_styled_text(" · ", style);
			else
			cout << get_styled_text(" " + to_string(board2[i][j]) + " ", style);
            }

            // Print the vertical divider for each block.
            if ((j + 1) % 3 == 0)
                cout << "|";
        }
        cout << endl;
    }
}

void initialize()
{
    // Set up styled text for Windows.
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

    // Mark editable cells
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            editable[i][j] = !board[i][j];

    // Print the initial board out.
    print_board(1);
}

void set_board(int n) 
{
    for(int i = 0; i < 9; i++) 
	{
        for(int j = 0; j < 9; j++) 
		{
            switch(n) 
			{
                case 1:
                    board[i][j] = a1[i][j];
                    break;
                case 2:
                    board[i][j] = a2[i][j];
                    break;
                case 3:
                    board[i][j] = a3[i][j];
                    break;
            }
        }
    }
}

void rest_number()
{
	int t[9]={0};
	for(int i = 0; i < 9; i++) 
	{
        for(int j = 0; j < 9; j++) 
		{
          if(board2[i][j]!=0)
		  {
          	t[board2[i][j]-1]+=1;
		  }
        }
    }	
    for(int i=0;i<9;i++)
	{
		cout <<i+1 << get_styled_text("still needs:", "B") << 9-t[i] << endl;
	}
}
int main()
{
	 // 使用當前時間作為亂數種子
    srand(time(NULL));
    
    // 產生 1-3 的亂數，選擇棋盤
    int board_num = rand() % 3 + 1;
    
    // 設定選擇的棋盤
    set_board(board_num);
    
    char c;
    bool action_ok;

    initialize();
    
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            board2[i][j] =board[i][j];
    
    int count;
    count=1;
    while (cin >> c)
    {
    	count+=1;
        action_ok = false;
        if (is_moving_action(c))
        {
            action_ok = true;
            move_cursor(c);
        }

        if (is_filling_action(c))
        {
            action_ok = true;
            fill_number(c);
        }

        if (c == 'Q' || c == 'q')
            break;
            
        print_board(count);
            
        if (c=='H'||c=='h')
        {
        	action_ok = true;
        	//cout<<"let me show you the ans. little kid..."<<endl;
        	show_ans(board_num);
		}

        if (check_win())
        {
            cout << "YOU WIN!" << endl;
            break;
        }
        else rest_number();

        if (!action_ok)
            cout << get_styled_text("!!! Invalid action !!!", "R");
    }

    return 0;
}
