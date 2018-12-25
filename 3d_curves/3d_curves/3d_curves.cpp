#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include"Figures.h"
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC


using namespace std;

int main()
{
	Figure *figures;
	vector<Figure*> v;
	for (int i = 0; i < 10; ++i)
	{
		if (i == 1 || i == 3 || i == 9 || i == 0)
		{
			figures = new circle;
		}
		else if (i == 2 || i == 4 || i == 8)
		{
			figures = new ellipse;
		}
		else
		{
			figures = new helixes;
		}
		figures->setRadius();
		figures->setX0();
		figures->setY0();
		figures->setZ0();
		v.push_back(figures);
	}
	/*unique_ptr<Figure> figures;
	vector<unique_ptr<Figure>> v;
	for (int i = 0; i < 10; ++i)
	{
		if (i == 1 || i == 3 || i == 9 || i == 0)
		{
			unique_ptr<Figure> figures(new circle);
		}
		else if (i == 2 || i == 4 || i == 8)
		{
			unique_ptr<Figure> figures(new ellipse);
		}
		else
		{
			unique_ptr<Figure> figures(new helixes(45));
		}
		//figures->setT(45);
		figures->setRadius();
		figures->setX0();
		figures->setY0();
		figures->setZ0();
		v.push_back(figures);
	}*/
	cout << "=====================================First vector=====================================" << endl;
	for (int i = 0; i < 10; ++i)
	{
		v[i]->show();
	}

	cout << "\n====================================Second vector=====================================" << endl;
	vector<Figure*> v1;
	//copy_if(v5.begin(), v5.end(), v2.begin(), [](Figure* i) {return i->figure_type == Circle_ID; });
	//copy_if(make_move_iterator(v5.begin()), make_move_iterator(v5.end()), back_inserter(v2), [](Figure* i) {return i->figure_type == Circle_ID; });

	auto p = stable_partition(v.begin(), v.end(), [](Figure* i) {return i->figure_type != Circle_ID; });
	v1.insert(v1.end(), make_move_iterator(p), make_move_iterator(v.end()));
	for (int i = 0; i < v1.size(); ++i)
	{
		v1[i]->show();
	}

	cout << "\n=====================================First vector=====================================" << endl;
	v.erase(p, v.end());
	for (int i = 0; i < v.size(); ++i)
	{
		v[i]->show();
	}
	sort(v1.begin(), v1.end(), [](Figure* a, Figure *b) {return a->rX < b->rX; });

	cout << "\n=================================Sorted Second vector=================================" << endl;
	for (int i = 0; i < v1.size(); ++i)
	{
		v1[i]->show();
	}
	float sum_radius = 0;
	for (int i = 0; i < v1.size(); ++i)
	{
		sum_radius += v1[i]->rX;
	}
	cout << "\nSum_Radius = " << sum_radius << endl;
	/*for (int i = 0; i < v.size(); ++i)
	{
		delete v[i];
	}
	for (int i = 0; i < v1.size(); ++i)
	{
		delete v1[i];
	}*/
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}

