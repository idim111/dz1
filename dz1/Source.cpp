#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
using namespace std;
using namespace sf;
const int Hi = 800;
const int bye = 800;
double func(double& formula, double x, string formyula, int ya_hz) {
	int mas[100];
	double sum = 0;
	int jk = 0;
	int jk2 = 0;
	int jk3 = 0;
	int power_of_10;
	double sum_func = 0;
	for (int i = 0; i < formyula.length(); i++) {
		//длинная проверка на число
		if (formyula[i] == '1' and i == 0 or formyula[i] == '2' and i == 0 or formyula[jk] == '3' and i == 0 or formyula[jk] == '4' and i == 0 or formyula[jk] == '5' and i == 0 or formyula[jk] == '6' and i == 0 or formyula[jk] == '7' and i == 0 or formyula[jk] == '8' and i == 0 or formyula[jk] == '9' and i == 0 or formyula[jk] == '0' and i == 0) {
			power_of_10 = 0;
			jk = i;
			jk3 = 0;
			jk2 = 0;
			sum_func = 0;
			//цикл нахождения полного числа 
			//с длинной проверкой
			while (formyula[jk] == '1' or formyula[jk] == '2' or formyula[jk] == '3' or formyula[jk] == '4' or formyula[jk] == '5' or formyula[jk] == '6' or formyula[jk] == '7' or formyula[jk] == '8' or formyula[jk] == '9' or formyula[jk] == '0') {
				mas[jk2] = formyula[jk] - 48;
				jk2++;
				jk++;
			}
			if (jk2 > 0) {
				for (int o = jk2 - 1; o >= 0; o--) {
					power_of_10 = pow(10, jk3);
					sum_func = sum_func + (power_of_10 * mas[o]);
					jk3++;
				}
			}
			sum = sum + sum_func;
		}
		//проверка на Х
		if (formyula[i] == 'x' and i == 0) {
			sum = sum + x;
		}
		//проверка на той или иной знак
		if (formyula[i] == '*' or formyula[i] == '-' or formyula[i] == '+' or formyula[i] == '/') {
			power_of_10 = 0;
			jk = i + 1;
			jk3 = 0;
			jk2 = 0;
			sum_func = 0;

			while (formyula[jk] == '1' or formyula[jk] == '2' or formyula[jk] == '3' or formyula[jk] == '4' or formyula[jk] == '5' or formyula[jk] == '6' or formyula[jk] == '7' or formyula[jk] == '8' or formyula[jk] == '9' or formyula[jk] == '0') {
				mas[jk2] = formyula[jk] - 48;
				jk2++;
				jk++;
			}
			if (jk2 > 0) {
				for (int o = jk2 - 1; o >= 0; o--) {
					power_of_10 = pow(10, jk3);
					sum_func = sum_func + (power_of_10 * mas[o]);
					jk3++;
				}
			}
			if (formyula[jk] == 'x') {
				sum_func = x;
			}
			if (formyula[i] == '*') {
				sum = sum * sum_func;
			}
			if (formyula[i] == '-') {
				sum = sum - sum_func;
			}
			if (formyula[i] == '/') {
				sum = sum / sum_func;
			}
			if (formyula[i] == '+') {
				sum = sum + sum_func;
			}
			i + jk - 2;
		}
	}
	return sum;
}
struct tochki {
	float x = 0;
	float y = 0;
};
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите любую функцию для Y\n";
	RenderWindow abobus(VideoMode(Hi, bye), "hello!");


	double xNul = 400;
	double yNul = 400;
	float mesto = 25;
	double x = 0;
	double y = 0;
	double x1 = 0;
	double y1 = 0;
	double j = 0;
	double x2;
	double y2;
	double formula;

	Font font;
	if (!font.loadFromFile("arial_bolditalicmt.ttf"))
	{
		return 0;
	}
	font.loadFromFile("arial_bolditalicmt.ttf");
	Text text;
	Text text2;
	Text text3;
	text2.setFont(font);
	text2.setString("X");
	text2.setCharacterSize(25);
	text2.setFillColor(Color::White);
	text3.setFont(font);
	text3.setString("Y");
	text3.setCharacterSize(25);
	text3.setFillColor(Color::White);
	text.setFont(font);
	text.setString("1 delenie == 25 pixel");
	text.setCharacterSize(25);
	text.setFillColor(Color::Green);
	CircleShape tochka(2.f);
	CircleShape tochka2(2.f);
	RectangleShape kvadrat(Vector2f(120.f, 50.f));
	RectangleShape kvadrat2(Vector2f(120.f, 50.f));
	kvadrat.setSize(sf::Vector2f(1.f, 1500.f));
	kvadrat2.setSize(Vector2f(1500.f, 1.f));
	kvadrat.setFillColor(Color::White);
	tochka.setFillColor(Color::Green);
	tochka2.setFillColor(Color::Green);
	text2.setPosition(Vector2f(5.f, 350.f));
	text3.setPosition(Vector2f(350.f, 750.f));
	text.setPosition(Vector2f(550.f, 780.f));

	string formyula;
	cin >> formyula;
	while (x1 < 800 or y1 < 800 or y1>0 or x1>0) {

		if (j == 0) {
			x = 0.01;
		}
		else {
			x = j;
		}

		y = func(formula, x, formyula,j);
		x2 = -j;
		y2 = func(formula, -x, formyula,j);
		x1 = xNul + x * mesto;
		y1 = yNul - y * mesto;
		tochka.setPosition(x1 - 2, y1 - 2);
		x1 = xNul + x2 * mesto;
		y1 = yNul - y2 * mesto;
		tochka2.setPosition(x1 - 2, y1 - 2);
		j++;
		if (y1 < 0 and j>0 or x1 < 0 and j>0 or x1 > 800 and j > 0 or y1 > 800 and j < 0) {
			break;
		}
	}
	int N = j;
	sf::VertexArray lines(LineStrip, N);
	sf::VertexArray lines2(LineStrip, N);
	while (abobus.isOpen()) {
		Event hello;
		while (abobus.pollEvent(hello)) {
			if (hello.type == Event::Closed) {
				abobus.close();
			}
		}

		

		abobus.clear(Color::Black);
		kvadrat.setPosition(400, 0);
		abobus.draw(kvadrat);
		kvadrat2.setPosition(0, 400);
		abobus.draw(kvadrat2);
		abobus.draw(text);
		abobus.draw(text2);
		abobus.draw(text3);

		RectangleShape palochka[100];
		RectangleShape strelochka[4];





		strelochka[0].setSize(Vector2f(30.f, 3.f));
		strelochka[0].rotate(40.f);
		strelochka[0].setPosition(776, 376);
		abobus.draw(strelochka[0]);
		strelochka[1].setSize(Vector2f(30.f, 3.f));
		strelochka[1].rotate(-40.f);
		strelochka[1].setPosition(775, 425);
		abobus.draw(strelochka[1]);
		strelochka[2].setSize(Vector2f(30.f, 3.f));
		strelochka[2].rotate(-45.f);
		strelochka[2].setPosition(376, 27);
		abobus.draw(strelochka[2]);
		strelochka[3].setSize(Vector2f(30.f, 3.f));
		strelochka[3].rotate(45.f);
		strelochka[3].setPosition(406, 7);
		abobus.draw(strelochka[3]);




		for (int i = 1; i < 51; i++) {
			palochka[i].setSize(Vector2f(20.f, 1.f));
			palochka[i].setPosition(390, i * 25);
			abobus.draw(palochka[i]);
		}
		for (int i = 1; i < 51; i++) {
			palochka[i].setSize(Vector2f(1.f, 20.f));
			palochka[i].setPosition(i * 25, 390);
			abobus.draw(palochka[i]);
		}




		
		j = 0;
		while (x1 < 800 or y1 < 800 or y1>0 or x1>0) {
			if (j == 0) {
				x = 0.0399999;
			}
			else {
				x = j;
			}
			

			y = func(formula, x, formyula, j);
			x2 = -j;
			y2 = func(formula, -x, formyula,j);
			x1 = xNul + x * mesto;
			y1 = yNul - y * mesto;
			
			//cout << x1 - 400 << " " << (y1 - 400) * -1 << "\n";
			tochka.setPosition(x1 - 2, y1 - 2);

			abobus.draw(tochka);
			lines[j].position = Vector2f(x1, y1);	
			lines[j].color = sf::Color::Red;
			x1 = xNul + x2 * mesto;
			y1 = yNul - y2 * mesto;
			tochka2.setPosition(x1 - 2, y1 - 2);
			abobus.draw(tochka2);
			lines2[j].position = Vector2f(x1, y1);
			lines2[j].color = sf::Color::Red;
			j++;
			if (y1 < 0  or x1 < 0  or x1 > 800  or y1 > 800 and j<0 ) {
				break;
			}
		}
		//cout << "\n\n\n\n";
		abobus.draw(lines);
		abobus.draw(lines2);
		abobus.display();
	}
}