#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 830
#define SPAWN_POS_X 10
#define SPAWN_POS_Y 0

void show_number(SDL_Renderer* renderer, int screen_width, int screen_height, int pixel_size,int number)
{
	static const int game_score[10][7][5] = {
		{
			{0,1,1,1,0},
			{1,0,0,0,1},
			{1,0,0,0,1},
			{1,0,0,0,1},
			{1,0,0,0,1},
			{1,0,0,0,1},
			{0,1,1,1,0}
		},
		{
			{0,0,0,1,0},
			{0,0,1,1,0},
			{0,1,1,1,0},
			{0,0,0,1,0},
			{0,0,0,1,0},
			{0,0,0,1,0},
			{0,1,1,1,1}
		},
		{
			{0,1,1,1,0},
			{1,0,0,0,1},
			{1,0,0,0,1},
			{0,0,0,1,0},
			{0,0,1,0,0},
			{0,1,0,0,0},
			{1,1,1,1,1}
		},
		{
			{0,1,1,1,0},
			{1,0,0,0,1},
			{0,0,0,0,1},
			{0,1,1,1,0},
			{0,0,0,0,1},
			{1,0,0,0,1},
			{0,1,1,1,0}
		},
		{
			{0,0,1,1,0},
			{0,1,0,1,0},
			{0,1,0,1,0},
			{1,0,0,1,0},
			{1,1,1,1,1},
			{0,0,0,1,0},
			{0,0,0,1,0}
		},
		{
			{1,1,1,1,1},
			{1,0,0,0,0},
			{1,1,1,1,0},
			{1,0,0,0,1},
			{0,0,0,0,1},
			{1,0,0,0,1},
			{0,1,1,1,0}
		},
		{
			{0,1,1,1,0},
			{1,0,0,0,1},
			{1,0,0,0,0},
			{1,1,1,1,0},
			{1,0,0,0,1},
			{1,0,0,0,1},
			{0,1,1,1,0}},
		{
			{1,1,1,1,1},
			{0,0,0,0,1},
			{0,0,0,1,0},
			{0,0,1,0,0},
			{0,0,1,0,0},
			{0,0,1,0,0},
			{0,0,1,0,0}
		},
		{
			{0,1,1,1,0},
			{1,0,0,0,1},
			{1,0,0,0,1},
			{0,1,1,1,0},
			{1,0,0,0,1},
			{1,0,0,0,1},
			{0,1,1,1,0},
		},
		{
			{0,1,1,1,0},
			{1,0,0,0,1},
			{1,0,0,0,1},
			{0,1,1,1,1},
			{0,0,0,0,1},
			{1,0,0,0,1},
			{0,1,1,1,0}
		},
	};
        int matrix_width = 5 * pixel_size;                
        int matrix_height = 7 * pixel_size;                
        int start_x = (screen_width - matrix_width) / 2;   
        int start_y = (screen_height - matrix_height) / 2; 
	for(int i=0;i<7;++i)
	{
		for(int j=0;j<5;++j)
		{
			if(game_score[number][i][j]==1)
			{
				SDL_Rect pixel_rect;
				SDL_SetRenderDrawColor(renderer,0,240,240,255);
                                pixel_rect.x = start_x + ((5 + j) * pixel_size);                                           
                                pixel_rect.y = start_y + (i * pixel_size);                                                 
                                pixel_rect.w = pixel_size - 1;
                                pixel_rect.h = pixel_size - 1;                                                             
                                SDL_RenderFillRect(renderer, &pixel_rect);                                                 
			}
		}
	}
}

void render_game_score_screen(SDL_Renderer* renderer, int screen_width, int screen_height, int pixel_size, int color_flag1, int color_flag2)
{
	static const int game_score_matrix[7][31] = {
	{0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,0},
	{0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0},
	{0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0},
	{0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,1,1,1,0,0,1,1,1,1,1,0},
	{0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0},
	{0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0},
	{0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,0,0,0,1,0,1,1,1,1,1,0}
	};
 	int matrix_width = 31 * pixel_size;                
 	int matrix_height = 7 * pixel_size;               
 	int start_x = (screen_width - matrix_width) / 2;   
 	int start_y = (screen_height - matrix_height) / 2; 
	for(int i=0;i<7;++i)
	{
		for(int j=0;j<31;++j)
		{
			if(game_score_matrix[i][j] == 1)
			{
				switch(color_flag2)
				{
					case 0:
					SDL_SetRenderDrawColor(renderer,color_flag1,30,color_flag1,255);
					break;
					case 1:
					SDL_SetRenderDrawColor(renderer,color_flag1,color_flag1,30,255);
					break;
					case 2:                                                          
					SDL_SetRenderDrawColor(renderer,color_flag1,30,30,255); 
					break;                                                 
                                        case 3:                                                 
                                        SDL_SetRenderDrawColor(renderer,30,color_flag1,30,255); 
                                        break;                                                 
                                        case 4:                                                 
                                        SDL_SetRenderDrawColor(renderer,30,color_flag1,color_flag1,255); 
                                        break;
                                        case 5:                                                 
                                        SDL_SetRenderDrawColor(renderer,30,30,color_flag1,255); 
                                        break;
				}
				SDL_Rect pixel_rect;                                                                        
				pixel_rect.x = start_x + ((5 + j) * pixel_size);                                            
				pixel_rect.y = start_y + (i * pixel_size);                                                  
				pixel_rect.w = pixel_size - 1;
				pixel_rect.h = pixel_size - 1;                            
				SDL_RenderFillRect(renderer, &pixel_rect);                                   
			}
		}
	}
}

void render_game_over_screen(SDL_Renderer* renderer, int screen_width, int screen_height, int pixel_size) {
    	static const int game_over_matrix[21][59] = {
        	{0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,0,0,0,1,0,1,1,1,1,1,0,1,1,1,1,0,0,0,1,0,0,0,0},
        	{0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,1,1,0,1,1,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0},
        	{0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1,1,0,1,1,0,1,1,1,1,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,1,1,0,1,1,1,1,0,0,0,1,0,0,0,0},
        	{0,0,0,1,0,0,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0},
        	{0,0,0,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,1,0,0,1,0,0,0,0},
        	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        	{1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,0,0,0,1,1,1,0,1,1,1,0,1,0,1,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1},
        	{1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,1,1,1,0,0,0,1},
        	{1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,0,0,0,0,1,0,0,1,1,1,0,0,1,0,0,0,0,1,1,1,0,1,0,1,0,1,1,1,0,0,1,0,0,1,0,1,0,0,1,1},
        	{1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0},
        	{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,0,0,1,0},
        	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    	};
    	int matrix_width = 59 * pixel_size;
    	int matrix_height = 21 * pixel_size;
    	int start_x = (screen_width - matrix_width) / 2;
    	int start_y = (screen_height - matrix_height) / 2;
    	for (int i = 0; i < 21; i++) {
        	for (int j = 0; j < 59; j++) {
            		if (game_over_matrix[i][j] == 1) 
			{
                		if (i < 6) SDL_SetRenderDrawColor(renderer, 255, 60, 60, 255);
                		else if (i >= 8 && i <= 12) SDL_SetRenderDrawColor(renderer, 220, 220, 220, 255);
                		else SDL_SetRenderDrawColor(renderer, 50, 255, 50, 255);
                		SDL_Rect pixel_rect;
                		pixel_rect.x = start_x + ((5 + j) * pixel_size);
                		pixel_rect.y = start_y + (i * pixel_size);
                		pixel_rect.w = pixel_size - 1;
                		pixel_rect.h = pixel_size - 1;
                		SDL_RenderFillRect(renderer, &pixel_rect);
            		}
        	}
    	}
}

int board[40][20] = {0};
int score = 0;
int isfinished = 0;

typedef struct{
	int POS_X;
	int POS_Y;
}Rect;

typedef struct{
	int r;
	int g;
	int b;
	int seed;
}Color;

typedef struct{
	Rect rect[4];
	Color color;
	int Attribute;
}rect_combine;

Color palette[7] ={
	(Color){  0  , 240 , 240 , 1 },
	(Color){ 240 , 240 ,  0  , 2 },
	(Color){ 160 ,  0  , 240 , 3 },
	(Color){  0  , 240 ,  0  , 4 },
	(Color){ 240 ,  0  ,  0  , 5 },
	(Color){  0  ,  0  , 240 , 6 },
	(Color){ 240 , 160 ,  0  , 7 },
};

void lock_block(rect_combine* cb);
Color color_initialize();
rect_combine rect_combine_initialize();
void line_clearance();
void block_rotate(rect_combine* cb);

Color color_initialize()
{
	Color cl;
	cl.seed = rand()%7;
	cl = palette[cl.seed];
	return cl;
}

rect_combine rect_combine_initialize()
{
	rect_combine cb;
	cb.color = color_initialize();
	cb.Attribute = rand()%7;
	cb.rect[1].POS_X = SPAWN_POS_X;
	cb.rect[1].POS_Y = SPAWN_POS_Y;
	switch (cb.Attribute)
	{
		case 0:
		cb.rect[0] = (Rect){cb.rect[1].POS_X-1,cb.rect[1].POS_Y};
		cb.rect[2] = (Rect){cb.rect[1].POS_X+1,cb.rect[1].POS_Y};
		cb.rect[3] = (Rect){cb.rect[1].POS_X+2,cb.rect[1].POS_Y};
		break;
		case 1:
                cb.rect[0] = (Rect){cb.rect[1].POS_X-1,cb.rect[1].POS_Y}; 
                cb.rect[2] = (Rect){cb.rect[1].POS_X+1,cb.rect[1].POS_Y}; 
                cb.rect[3] = (Rect){cb.rect[1].POS_X+1,cb.rect[1].POS_Y+1}; 
		break;
                case 2:                                                      
                cb.rect[0] = (Rect){cb.rect[1].POS_X-1,cb.rect[1].POS_Y};    
                cb.rect[2] = (Rect){cb.rect[1].POS_X+1,cb.rect[1].POS_Y};    
                cb.rect[3] = (Rect){cb.rect[1].POS_X,cb.rect[1].POS_Y+1};  
                break;                                                       
                case 3:                                                      
                cb.rect[0] = (Rect){cb.rect[1].POS_X-1,cb.rect[1].POS_Y};    
                cb.rect[2] = (Rect){cb.rect[1].POS_X+1,cb.rect[1].POS_Y};    
                cb.rect[3] = (Rect){cb.rect[1].POS_X-1,cb.rect[1].POS_Y+1};  
                break;                                                       
                case 4:                                                      
                cb.rect[0] = (Rect){cb.rect[1].POS_X-1,cb.rect[1].POS_Y};    
                cb.rect[2] = (Rect){cb.rect[1].POS_X,cb.rect[1].POS_Y+1};    
                cb.rect[3] = (Rect){cb.rect[1].POS_X+1,cb.rect[1].POS_Y+1};  
                break;                                                       
                case 5:                                                      
                cb.rect[0] = (Rect){cb.rect[1].POS_X-1,cb.rect[1].POS_Y};    
                cb.rect[2] = (Rect){cb.rect[1].POS_X-1,cb.rect[1].POS_Y+1};    
                cb.rect[3] = (Rect){cb.rect[1].POS_X,cb.rect[1].POS_Y+1};  
                break;                                                       
                case 6:                                                      
                cb.rect[0] = (Rect){cb.rect[1].POS_X+1,cb.rect[1].POS_Y};    
                cb.rect[2] = (Rect){cb.rect[1].POS_X,cb.rect[1].POS_Y+1};    
                cb.rect[3] = (Rect){cb.rect[1].POS_X-1,cb.rect[1].POS_Y+1};  
                break;                                                       
	}
	return cb;
}

/*we must use a pointer here!
  when we call a function in C
  the system copy a cb as cb' in the function
  it just operate the cb' instead of cb
  as a result
  the real cb is not changed yet
  the solution is to use a pointer
  when we use the pointer to change the struct
  the real cb is changed*/
void move_block(SDL_Event e,rect_combine* cb)
{
	int flag1 = 1,flag2 = 1,islock = 0;
	for(int i=0;i<4;++i)
	{
		if(cb->rect[i].POS_X == 1 || board[cb->rect[i].POS_Y][cb->rect[i].POS_X-2] != 0) 
			flag1 = 0;
		if(cb->rect[i].POS_X == 20 || board[cb->rect[i].POS_Y][cb->rect[i].POS_X] != 0) 
			flag2 = 0;
		if(cb->rect[i].POS_Y == 39 || board[cb->rect[i].POS_Y+1][cb->rect[i].POS_X-1] != 0)
			islock = 1;
	}
	if(e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
			case SDLK_a:
			for(int i=0;i<4;++i)
			{
				cb->rect[i].POS_X -= flag1;
			}
			break;
                        case SDLK_d:                   
                        for(int i=0;i<4;++i)           
                        {                              
                                cb->rect[i].POS_X += flag2; 
                        }                              
                        break;                         
                        case SDLK_s:                   
			if(islock) lock_block(cb);
			else{
                        	for(int i=0;i<4;++i)           
                        	{                              
                                	cb->rect[i].POS_Y += 1; 
                        	}
			}                              
                        break;                       
			case SDLK_SPACE:
			block_rotate(cb);
			break;
			default:
			break;  
		}
	}
}

void block_drop(rect_combine* cb)
{
	int islock = 0;
	for(int i=0;i<4;++i)
	{
        	if(cb->rect[i].POS_Y == 39 ||board[cb->rect[i].POS_Y+1][cb->rect[i].POS_X-1] != 0) 
                	islock = 1;                                                                
	}
        if(islock) lock_block(cb);               
        else{                                    
                for(int i=0;i<4;++i)             
                {                                
                        cb->rect[i].POS_Y += 1;  
                }                                
        }                                        	                              
}

void lock_block(rect_combine* cb)
{
	for(int i=0;i<4;++i)
	{
		board[cb->rect[i].POS_Y][cb->rect[i].POS_X-1] = cb->color.seed;
	}
	line_clearance();
	*cb = rect_combine_initialize();
	for(int i=0;i<4;++i)
	{
		if(board[cb->rect[i].POS_Y][cb->rect[i].POS_X-1]!=0)
		{
			isfinished = 1;
			break;
		}
	}
}

void background_initialize(SDL_Renderer* renderer,SDL_Rect rect[40][20],int color_flag1,int color_flag2)
{
	SDL_SetRenderDrawColor(renderer,40,30,30,255);
	for(int i=0;i<40;++i)
	{
		for(int j=0;j<20;++j)
		{
			if(board[i][j] == 0) SDL_RenderFillRect(renderer,&rect[i][j]);
			else{
				SDL_SetRenderDrawColor(
				renderer,
				palette[board[i][j]-1].r,
				palette[board[i][j]-1].g,
				palette[board[i][j]-1].b,
				255);
				SDL_RenderFillRect(renderer,&rect[i][j]);
				SDL_SetRenderDrawColor(renderer,40,30,30,255);
			}
		}
	}
	show_number(renderer,460,800,10,0);
	show_number(renderer,345,800,10,(score/10)%10);
	show_number(renderer,230,800,10,(score/100)%10);
	show_number(renderer,115,800,10,(score/1000)%10);
	show_number(renderer,0,800,10,(score/10000));
	render_game_score_screen(renderer,230,400,10,color_flag1,color_flag2); 
}

void line_clearance()
{
	int flag = 0,lines_cleared = 0;
	for(int i=39;i>=0;--i)
	{
		for(int j=0;j<20;++j)
		{
			flag = (board[i][j] == 0);
			if(flag) break;
		}
		if(!flag)
		{
			++lines_cleared;
			for(int k=i;k>=1;--k)
			{
				for(int j=0;j<20;++j)
				{
					board[k][j] = board[k-1][j];
				}
			}
			for(int j=0;j<20;++j)
			{
				board[0][j] = 0;
			}
			++i;
		}
	}
	switch(lines_cleared)
	{
		case 1:
		score += 10;
		break;
		case 2:
		score += 30;
		break;
		case 3:
		score += 60;
		break;
		case 4:
		score += 100;
		break;
	}
}

void block_rotate(rect_combine* cb)
{
	int flag = 0;
	rect_combine temp;
	for(int i=0;i<4;++i)
	{
		temp.rect[i].POS_X = cb->rect[1].POS_X - cb->rect[i].POS_Y + cb->rect[1].POS_Y;
		temp.rect[i].POS_Y = cb->rect[1].POS_Y + cb->rect[i].POS_X - cb->rect[1].POS_X;
		flag =  temp.rect[i].POS_Y < 0 ||
			temp.rect[i].POS_Y > 39 ||
			temp.rect[i].POS_X < 1 ||
			temp.rect[i].POS_X > 20 || 
			(board[temp.rect[i].POS_Y][temp.rect[i].POS_X-1] != 0) ;
		if(flag) break;
	}
	if(!flag)
	{
		for(int i=0;i<4;++i)
		{
			cb->rect[i].POS_X = temp.rect[i].POS_X;
			cb->rect[i].POS_Y = temp.rect[i].POS_Y;
		}
	}
}

void clear_board()
{
	for(int i=0;i<40;++i)
	{
		for(int j=0;j<20;++j)
		{
			board[i][j] = 0;
		}
	}
}

void background_clear(SDL_Renderer* renderer,SDL_Rect rect[40][20])              
{                                                                                     
        SDL_SetRenderDrawColor(renderer,40,30,30,255);                                
        for(int i=0;i<40;++i)                                                         
        {                                                                             
                for(int j=0;j<20;++j)                                                 
                {                                                 
                        SDL_RenderFillRect(renderer,&rect[i][j]);
		}                                                                     
        }                                                                             
}                                                                                     

void main()
{
	srand(time(NULL));
	int isrunning = 1;
	int color_flag1 = 40,color_flag2 = 240,color_flag3 = 0;
	Uint32 last_time1 = 0;
	Uint32 last_time2 = 0;
	rect_combine cb = rect_combine_initialize();	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow(
	"Retro Tetris",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	WINDOW_WIDTH,
	WINDOW_HEIGHT,
	SDL_WINDOW_SHOWN
	);
	SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
	SDL_Event event;
	
        SDL_Rect rect[40][20];                                                                  
        for(int i=0;i<40;++i)                                              
        {                                                                  
                for(int j=0;j<20;++j)                                      
                {                                                          
                        rect[i][j]=(SDL_Rect){320+20*j,20+20*i,16,16};
                }                                                          
        }                                                                  


	while(isrunning)
	{
		while(!isfinished)
		{
			if(SDL_GetTicks() - last_time2 >20)
			{
				last_time2 = SDL_GetTicks();
				if(color_flag1 <= 240) 
				{
					color_flag1 += 5;
					if(color_flag1 == 240) color_flag2 = 240;
				}
				else
				{
					color_flag2 -=5;
					if(color_flag2 == 40)
					{ 
						color_flag1 = 40;
						color_flag3 = rand()%6;
					}
				}
			}
			if(SDL_GetTicks() - last_time1 > 500)
			{
				last_time1 = SDL_GetTicks();
				block_drop(&cb);
			}
			while(SDL_PollEvent(&event))           
			//This while is to monitor event,if one event is triggered,we get inside this while 
			{
				if(event.type == SDL_QUIT) 
				{
					isfinished = 1;
					isrunning = 0;      //to monitor if event is quit
					break;
				}
				else move_block(event,&cb);
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,255);
			SDL_RenderClear(renderer);
			if(color_flag1<=240) background_initialize(renderer,rect,color_flag1,color_flag3);
			else background_initialize(renderer,rect,color_flag2,color_flag3);
			SDL_SetRenderDrawColor(renderer,cb.color.r,cb.color.g,cb.color.b,255);
			for(int i=0;i<4;++i)
			{
				SDL_RenderFillRect(renderer,
				&(SDL_Rect){300+20*cb.rect[i].
				POS_X,20+20*cb.rect[i].POS_Y,16,
				16});
			}
			SDL_RenderPresent(renderer);
			SDL_Delay(16);
		}
		if(!isrunning) break;
		score = 0;
		while(isfinished)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            		SDL_RenderClear(renderer);
			render_game_over_screen(renderer, 860, 630, 16);
			while(SDL_PollEvent(&event))
			{
				if(event.type == SDL_KEYDOWN)
				{
					if(event.key.keysym.sym == SDLK_y)
					{
						isfinished = 0;
						clear_board();
						background_clear(renderer,rect);
					}
					else if(event.key.keysym.sym == SDLK_n)
					{
						isfinished = 0;
						isrunning = 0;
					}
				}
			}
			SDL_RenderPresent(renderer);
			SDL_Delay(16);
		}
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
