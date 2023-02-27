#include<iostream>
using namespace std;

#define elif else if

struct Rect{
	double x,y,w,h;
};

class collider 
{
	public:
		double x_finish,x_start,y_finish,y_start;

		void set_Var(Rect Argu)
		{
			x_start = Argu.x;
			x_finish = Argu.x + Argu.w;

			y_start = Argu.y;
			y_finish = Argu.y-Argu.h;
		}
};

double overlap(Rect R1, Rect R2)
{
	collider x1, x2;
	x1.set_Var(R1);
	x2.set_Var(R2);

	#define y1 x1
	#define y2 x2

	bool Overlap_x [] = {
		(x1.x_start >= x2.x_start && x1.x_finish <= x2.x_finish), //สั้นกว่า
		(x1.x_start >= x2.x_start && x1.x_finish >= x2.x_finish), //บางส่วนหน้่า
		(x1.x_start <= x2.x_start && x1.x_finish <= x2.x_finish  && x1.x_finish > x2.x_start), //บางส่วนหลัง
		(x1.x_start <= x2.x_start && x1.x_finish >= x2.x_finish), //ยาวกว้า
		((x1.x_start < x2.x_start && x1.x_finish < x2.x_finish) || (x1.x_start > x2.x_start && x1.x_finish > x2.x_finish)) //ไม่ทับกันเลย
	};

	bool Overlap_y [] = {
		(y1.y_start <= y2.y_start && y1.y_finish >= y2.y_finish), //สั้นกว่า
		(y1.y_start <= y2.y_start && y1.y_finish <= y2.y_finish && y1.y_start > y2.y_finish), //บางส่วนหน้่า
		(y1.y_start >= y2.y_start && y1.y_finish >= y2.y_finish  && y1.y_finish < y2.y_start), //บางส่วนหลัง
		(y1.y_start >= y2.y_start && y1.y_finish <= y2.y_finish), //ยาวกว้า
		((y1.y_start > y2.y_start && y1.y_finish > y2.y_finish) || (y1.y_start < y2.y_start && y1.y_finish < y2.y_finish)) //ไม่ทับกันเลย
	};

	double Over_x,Over_y;


	if(Overlap_x[0])
	{
		Over_x = R1.w;
		//cout << "Overlap_x type 1 \n";
	}
	elif(Overlap_x[1])
	{
		Over_x = x2.x_finish - x1.x_start;
		//cout << "Overlap_x type 2 \n";
	}
	elif(Overlap_x[2])
	{
		Over_x = x1.x_finish - x2.x_start;
		//cout << "Overlap_x type 3 \n";
	}
	elif(Overlap_x[3])
	{
		Over_x = R2.w;
		//cout << "Overlap_x type 4 \n";
	}
	elif(Overlap_x[4])
	{
		Over_x = 0;
		//cout << "Overlap_x type 5 \n";
	}


	if(Overlap_y[0])
	{
		Over_y = R1.h;
		//cout << "Overlap_y type 1 \n";
	}
	elif(Overlap_y[1])
	{
		Over_y = y1.y_start - y2.y_finish;
		//cout << "Overlap_y type 2 \n";
	}
	elif(Overlap_y[2])
	{
		Over_y = y2.y_start - y1.y_finish;
		//cout << "Overlap_y type 3 \n";
	}
	elif(Overlap_y[3])
	{
		Over_y  = R2.h;
		//cout << "Overlap_y type 4 \n";
	}
	elif(Overlap_y[4])
	{
		Over_y = 0;
		//cout << "Overlap_y type 5 \n";
	}

	cout << Over_x << " " << Over_y << endl;

	return Over_x * Over_y;
}

int main()
{
	Rect R1 = {1,1,5,5}; //debug case 1
	Rect R2 = {2,2,5,5};	
	cout << overlap(R1,R2) << endl;	

	R1 = {1,1,5,5}; //debug case  2
	R2 = {7,2,3,3};	
	cout << overlap(R1,R2) << endl;	

	R1 = {-1,2,6.9,9.6};  //debug case 3
	R2 = {0,0,1.2,2.5};	
	cout << overlap(R1,R2) << endl;	
}