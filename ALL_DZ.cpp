/* Колодчук Алексей, 10И2. */
#include "windows.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// ОБЯЗАТЕЛЬНО ПРОЧИТАЙТЕ!
/*
 * В главном меню вводится номер дз.
 * Если дз №4, 7 или 8, то во внутреннем меню вводится номер задания.
 * Если дз №5, то в подменю вводится число:
 * - 1 соответствует дз №5 в статических массивах,
 * - 2 соответствует дз №5 в одномерных динамических массивах.
 * Затем следует внутреннее меню.
 * Во всех видах меню вводится также число 0, чтобы выйти в меню наверх.
 * В главном меню ввод 0 означает выход из программы.
 * 
 * Код структурирован и имеет комментарии + закомментированные условия задач,
 * чтобы можно было всё удобнее проверять. Я бы добавил условия прямо в
 * программу, но добавление русского языка муторно и не факт что сработает.
 * 
 * В этой программе:
 * ДЗ №4: задачи №4, 5, 7 и 8,
 * ДЗ №5: статические массивы - задачи с №1 по №8,
 *        динамические одномерные - задачи с №1 по №8,
 * ДЗ №6: задачи с №1 по №7,
 * ДЗ №7: задачи с №1 по №8.
 * 
 * Если вы случайно ввели в задаче вместо цифр символы и программа поломалась,
 * пожалуйста, нажмите Ctrl+C 2 раза.
 * 
 * Компилировалось в GCC, писалось в notepad.exe и в Geany.
 */
 
int dz7task1() {
	string s;
	bool isHere=false;
	char p;
	cout << "Task 1. String = ";
	getline(cin, s);
	cout << "Symbol = ";
	cin >> p;
	for (long long unsigned int i=0; i<s.size(); i++) {
		if (s[i]==p) { isHere=true; }
	}
	if (isHere) { cout << "\nSymbol IS in this string.\n\n"; }
	else { cout << "\nSymbol is NOT in this string.n\n"; }
	return 0;
}

int main() {
	string start = "|========================================================|\n|               Alex Kolodchuk's homework:               |\n|                DZ4: [4, 5, 7, 8]                       |\n|                DZ5:                                    |\n|                 Static [1-8]                           |\n|                 Dynamic one-dm [1-8]                   |\n|                DZ6: [1-7]                              |\n|                DZ7: [1-8]                              |\n|========================================================|\n\n";
	for (long long unsigned int i=0; i<start.size(); i++) { cout << start[i]; Sleep(5); }
	
	bool as=false;
	while (1) {
		string chdz, ch5dz, chtask;
		cout << "\n\n|--------------------------------------------------------| \n          [4, 5, 6, 7, 0 to exit] Homework No: ";
		cin >> chdz;
		cout << "|--------------------------------------------------------| \n\n";
		
		long long int x, i; //unsigned long long int y;
		string choice, s, q; //unsigned long int N;

		// ДЗ 4. Номера 4, 5, 7, 8.
		if (chdz=="4") {
			while (1) {
				cout << "\n/-------------DZ4 (0 is exit to main menu)--------------\\\n     Write number of task (integer 4, 5, 7, 8, 0): ";
				cin >> chtask;
				cout << "\\-------------------------------------------------------/\n";

			   /* ДЗ4, номер 4.
			   Вывести на экран все числа Фибоначчи до i-того члена ряда. Число i задается пользователем.
			   */
				if (chtask=="4") {
					cout << "\nTask 4.\ni = "; cin >> x;
					if (x<=0) { cout << "Incorrect input.\n\n"; }
					else if (x==1) { cout << "1\n\n"; }
					else if (x==2) { cout << "1, 1\n\n"; }
					else {
						s = "1, 1"; long int i1 = 1; long int i2 = 1; long int i3 = 2;
						for (i=1; i<=x-2; i++) {
						i3 = i1+i2; i1 = i2; i2 = i3; s+=", ";
						ostringstream q; q << i3; s+=q.str();
						}
					cout << s << "\n\n";
					}

			   /* ДЗ4, номер 5.
			   из чисел от 31 до 50 вывести на экран те из них, которые делятся на 3, но не делятся на 5.
			   Mod: числа от N до К, числа N и K задаются пользователем.
			   */
				} else if (chtask=="5") {
					cout << "\nTask 5."; s = ""; long unsigned int count = 0;
					for (i=31; i<=50; i++) {
						if (i%3==0 and i%5!=0) {
							count++;
							if (count==1) { ostringstream q; q << i; s+=q.str(); } 
							else { ostringstream q; q << i; s+=", "; s+=q.str(); }
						}
					}
					cout << "Classic version output: " << s << "\nStarting mod input. N, K = ";
					unsigned long int N, K;
					cin >> N >> K; s = ""; count = 0;
					for (i=N; i<=K; i++) {
						if (i%3==0 && i%5!=0) {
							count++;
							if (count==1) { ostringstream q; q << i; s+=q.str(); } 
							else { ostringstream q; q << i; s+=", "; s+=q.str(); }
						}
					}
					cout << "Modificated version output: " << s << ".\n\n";

			   /* ДЗ4, номер 7.
			   Вывести все делители заданного пользователем числа.
			   */
				} else if (chtask=="7") {
					cout << "\nTask 7.\nx = ";
					cin >> x;
					s = ""; long unsigned int count = 0;
					for (i=1; i<=x; i++) {
						if (x%i==0) {
							count++;
							if (count==1) { ostringstream q; q << i; s+=q.str(); } 
							else { ostringstream q; q << i; s+=", "; s+=q.str(); }
						}
					}
					cout << "Answer: " << s << ".\n\n";

			   /* ДЗ4, номер 8.
			   Удалить определенную цифру из заданного числа. Цифру и число задает пользователь.
			   Дополнительное условие: Разрядов в числе может быть до 10. Цифра может
			   входить в число несколько раз.
			   */
				} else if (chtask=="8") {
					cout << "\nTask 8.\nx, i = ";
					cin >> x >> i;
					long long int _x = x;
					long long unsigned int _w = 1,f=0, k=0, f1=f, __w = 0, X=0;
					while (_x>0) { __w++; _x=int(_x/10); }
					cout << __w << "\n";
					for (long unsigned int i=1; i<=__w; i++) {
						_w*=10;
						f = x%(_w);
						f1 = f;
						cout << f << "," << _w << "," << f1 << " " ;
						k = f;
					}
					cout << _w << "\n";

				} else if (chtask=="0") { break; }
			}

		// ДЗ 5. Только статические массивы и динамические одномерные массивы. 
		// Димнамические многомерные не делал.
		} else if (chdz=="5") {
			while (1) {
				cout << "\n/~~~~~~DZ5. Static [1], dynamic one-dm [2], exit [0]~~~~~\\\n        Write version of homework (integer 0-2): ";
				cin >> ch5dz;
				cout << "\\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/\n";

				// ДЗ5 Статические массивы. Номера от 1 до 8.
				if (ch5dz=="1") {
					while (1) {
						cout << "\n/---------------DZ5 (Static list version)----------------\\\n          Write number of task (integer 0-8): ";
						cin >> chtask;
						cout << "\\--------------------------------------------------------/\n";

					   /* ДЗ5 Статические массивы, номер 1.
					   Удалить в массиве все числа, которые повторяются более трех
					   раз.
					   */
						if (chtask=="1") {
							int _N;
							cout << "\nTask 1. N = ";
							cin >> _N;
							const int N = _N;
							int A[N];
							for (int i=0; i<N; i++) {
								cout << "A[" << i << "] = ";
								cin >> A[i];
							}
							
					   /* ДЗ5 Статические массивы, номер 2.
					   Введите одномерный целочисленный массив. Найдите второй
					   наибольший нечетный элемент и поменяйте его местами с
					   наибольшим четным.
					   */
						} else if (chtask=="2") {
							int _N, max_even, max_odd;
							cout << "\nTask 2. N = ";
							cin >> _N;
							const int N = _N;
							int A[N];
							for (int i=0; i<N; i++) {
								cout << "A[" << i << "] = ";
								cin >> A[i];
							}
							int B[N];
							string ai;
							for (int i=0; i<N; i++) {
								if (i==0) {
									max_even = A[i];
									max_odd = A[i];
									if (A[i]%2==0) {
										ai = "even";
									} else {
										ai = "odd";
									}
								} else {
									if (A[i]%2==0 && A[i]>max_even) {
										max_even = A[i];
									}
									if (A[i]%2==1 && A[i]>max_odd) {
										max_odd = A[i];
									}
								}
							}
							if (ai == "even" && max_odd%2==0) {
								for (int i=0;i<N;i++) {
									B[i] = A[i];
								}
							} else if (ai == "odd" && max_even%2==1) {
								for (int i=0;i<N;i++) {
									B[i] = A[i];
								}
							} else {
								for (int i=0;i<N;i++) {
									if (A[i] == max_even) {
										B[i] = max_odd;
									} else if (A[i] == max_odd) {
										B[i] = max_even;
									} else {
										B[i] = A[i];
									}
								}
							}
							cout << "Final list: [";
							for (int i=0;i<N-1;i++) {
								cout << B[i] << ", ";
							}
							cout << B[N-1] << "]\n\n";

					   /* ДЗ5 Статические массивы, номер 3.
					   Найдите сумму отрицательных элементов массива.
					   */
						} else if (chtask=="3") {
							long long int _N, sum=0;
							cout << "\nTask 3. N = ";
							cin >> _N;
							const long long int N = _N;
							int A[N];
							for (int i=0; i<N; i++) {
								cout << "A[" << i << "] = ";
								cin >> A[i];
								if (A[i]<0) { sum+=A[i]; }
							}
							cout << "Answer: " << sum << "\n";

					   /* ДЗ5 Статические массивы, номер 4.
					   Найдите произведение элементов массива с нечетными номерами.
					   */
						} else if (chtask=="4") {
							long long int _N, sum=1;
							cout << "\nTask 4. N = ";
							cin >> _N;
							const long long int N = _N;
							int A[N];
							for (int i=0; i<N; i++) {
								cout << "A[" << i << "] = ";
								cin >> A[i];
								if (i%2==1) { sum*=A[i]; }
							}
							cout << "Answer: " << sum << "\n";

					   /* ДЗ5 Статические массивы, номер 5.
					   Найдите сумму элементов массива между двумя первыми
					   нулями. Если двух нулей нет в массиве, то выведите ноль.
					   */
						} else if (chtask=="5") {
							long long int _N, i1=0, i2=0, all0 = 0, sum=0;
							cout << "\nTask 5. N = ";
							cin >> _N;
							const long long int N = _N;
							int A[N];
							for (int i=0; i<N; i++) {
								cout << "A[" << i << "] = ";
								cin >> A[i];
								if (A[i]==0) {
									all0++;
									if (all0==1) { i1=i; }
									else if (all0==2) { i2=i; }
								}
							}
							if (all0>=2) { for (int i=i1; i<i2; i++) sum+=A[i]; }
							cout << "Answer: " << sum << "\n";

					   /* ДЗ5 Статические массивы, номер 6.
					   Найдите наибольший элемент массива.
					   */
						} else if (chtask=="6") {
							long long int _N, big=0;
							cout << "\nTask 6. N = ";
							cin >> _N;
							const int N = _N;
							int A[N];
							for (int i=0; i<N; i++) {
								cout << "A[" << i << "] = ";
								cin >> A[i];
								if (i==0) { big=A[i]; }
								else { if (A[i]>big) { big=A[i]; } }
							}
							cout << "Answer: " << big << "\n";

					   /* ДЗ5 Статические массивы, номер 7.
					   Найдите второй наименьший четный элемент массива. Если
					   такого нет, то выведите первый элемент.
					   */
						} else if (chtask=="7") {
							long long int _N, _even=0, ec=0;
							cout << "\nTask 7. N = ";
							cin >> _N;
							const long long int N = _N;
							int A[N];
							for (int i=0; i<N; i++) {
								cout << "A[" << i << "] = ";
								cin >> A[i];
							}
							for (int i=0; i<N; i++) { if (A[i]%2==0) { _even++; } }
							const long long int even = _even;
							int Even[even];
							for (int i=0; i<N; i++) {
								if (A[i]%2==0) {
									ec++;
									Even[ec]=A[i];
								}
							}
							// Сортировка пузырьком по возрастанию из ДЗ6, номера 1.
							for (int i=0; i<even-1; i++) { for (int j=even-2; j>=i; j--) { if (Even[j] > Even[j+1]) { int c = Even[j]; Even[j] = Even[j+1]; Even[j+1] = c; } } }
							if (even==0) { cout << "Answer: there are no even numbers o_0\n"; }
							else if (even==1) { cout << "Answer: " << Even[0] << "\n"; }
							else { cout << "Answer: " << Even[1] << "\n"; }

					   /* ДЗ5 Статические массивы, номер 8.
					   Найдите произведение положительных элементов массива.
					   */
						} else if (chtask=="8") {
							long long int _N, sum=0;
							cout << "\nTask 8. N = ";
							cin >> _N;
							const long long int N = _N;
							int A[N];
							for (int i=0; i<N; i++) {
								cout << "A[" << i << "] = ";
								cin >> A[i];
								if (A[i]>0) { sum*=A[i]; }
							}
							cout << "Answer: " << sum << "\n";
						
						} else if (chtask=="0") { break; }
					}

				// ДЗ5 Динамические одномерные массивы. Номера от 1 до 8.
				} else if (ch5dz=="2") {
					while (1) {
						cout << "\n/-----------DZ5 (Dynamic one-dm list version)------------\\\n          Write number of task (integer 0-8): ";
						cin >> chtask;
						cout << "\\--------------------------------------------------------/\n";
						
					   /* ДЗ5 Динамические одномерные массивы, номер 1.
					   Удалить в массиве все числа, которые повторяются более трех
					   раз.
					   */
						if (chtask=="1") {
							vector <int> A;
							long long int a=1, c=0;
							cout << "\nTask 1.\n";
							while (a!=0) {
								cout << "A[" << c << "] = ";
								cin >> a;
								if (a!=0) { A.push_back(a); }
								c++;
							}
							for(long long unsigned i=0; i<A.size(); i++ ) { cout << A[i] << " "; }

					   /* ДЗ5 Динамические одномерные массивы, номер 2.
					   Введите одномерный целочисленный массив. Найдите второй
					   наибольший нечетный элемент и поменяйте его местами с
					   наибольшим четным.
					   */
						} else if (chtask=="2") {
							vector <int> A;
							long long int a=1, c=0, max_even, max_odd;
							cout << "\nTask 1.\n";
							while (a!=0) {
								cout << "A[" << c << "] = ";
								cin >> a;
								if (a!=0) { A.push_back(a); }
								c++;
							}
							vector <int> B;
							string ai;
							for (long long unsigned int i=0; i<A.size(); i++) {
								if (i==0) {
									max_even = A[i];
									max_odd = A[i];
									if (A[i]%2==0) {
										ai = "even";
									} else {
										ai = "odd";
									}
								} else {
									if (A[i]%2==0 && A[i]>max_even) {
										max_even = A[i];
									}
									if (A[i]%2==1 && A[i]>max_odd) {
										max_odd = A[i];
									}
								}
							}
							if (ai == "even" && max_odd%2==0) {
								for (long long unsigned int i=0;i<A.size();i++) {
									B[i] = A[i];
								}
							} else if (ai == "odd" && max_even%2==1) {
								for (long long unsigned int i=0;i<A.size();i++) {
									B[i] = A[i];
								}
							} else {
								for (long long unsigned int i=0;i<A.size();i++) {
									if (A[i] == max_even) {
										B[i] = max_odd;
									} else if (A[i] == max_odd) {
										B[i] = max_even;
									} else {
										B[i] = A[i];
									}
								}
							}
							cout << "Final list: [";
							for(long long unsigned i=0; i<B.size()-1; i++ ) { cout << B[i] << ", "; }
							cout << B[B.size()-1] << "]\n\n";

					   /* ДЗ5 Динамические одномерные массивы, номер 3.
					   Найдите сумму отрицательных элементов массива.
					   */
						} else if (chtask=="3") {
							vector <int> A;
							long long int a=1, c=0, sum=0;
							cout << "\nTask 1.\n";
							while (a!=0) {
								cout << "A[" << c << "] = ";
								cin >> a;
								if (a!=0) { A.push_back(a); if (a<0) { sum+=a; }}
								c++;
							}
							cout << "Answer: " << sum << "\n";

					   /* ДЗ5 Динамические одномерные массивы, номер 4.
					   Найдите произведение элементов массива с нечетными номерами.
					   */
						} else if (chtask=="4") {
							vector <int> A;
							long long int a=1, c=0, sum=0;
							cout << "\nTask 1.\n";
							while (a!=0) {
								cout << "A[" << c << "] = ";
								cin >> a;
								if (a!=0) { A.push_back(a); if (c%2==1) { sum*=a; }}
								c++;
							}
							cout << "Answer: " << sum << "\n";

					   /* ДЗ5 Динамические одномерные массивы, номер 5.
					   Найдите сумму элементов массива между двумя первыми
					   нулями. Если двух нулей нет в массиве, то выведите ноль.
					   */
						} else if (chtask=="5") {
							vector <int> A;
							long long int a=1, c=0, i1=0, i2=0, all0 = 0, sum=0;
							cout << "\nTask 1.\n";
							while (a!=0) {
								cout << "A[" << c << "] = ";
								cin >> a;
								if (a!=0) {
									A.push_back(a);
									if (a==0) {
										all0++;
										if (all0==1) { i1=i; }
										else if (all0==2) { i2=i; }
									}
								}
								c++;
							}
							if (all0>=2) { for (int i=i1; i<i2; i++) sum+=A[i]; }
							cout << "Answer: " << sum << "\n";

					   /* ДЗ5 Динамические одномерные массивы, номер 6.
					   Найдите наибольший элемент массива.
					   */
						} else if (chtask=="6") {
							vector <int> A;
							long long int a=1, c=0, big=0;
							cout << "\nTask 1.\n";
							while (a!=0) {
								cout << "A[" << c << "] = ";
								cin >> a;
								if (a!=0) {
									A.push_back(a);
									if (i==0) { big=A[i]; }
									else { if (A[i]>big) { big=A[i]; } }
								}
								c++;
							}
							cout << "Answer: " << big << "\n";

					   /* ДЗ5 Динамические одномерные массивы, номер 7.
					   Найдите второй наименьший четный элемент массива. Если
					   такого нет, то выведите первый элемент.
					   */
						} else if (chtask=="7") {
							vector <int> A;
							int a=1, c=0;
							cout << "\nTask 7.\n";
							while (a!=0) {
								cout << "A[" << c << "] = ";
								cin >> a;
								if (a!=0) { A.push_back(a); }
								c++;
							}
							vector <int> Even;
							for (int i=0; i<A.size(); i++) {
								if (A[i]%2==0) { Even.push_back(A[i]); } }
							// Сортировка пузырьком по неубыванию для векторов в одной строке.
							for (int i=0; i<Even.size()-1; i++) { for (int j=Even.size()-2; j>=i; j--) { if (Even[j] > Even[j+1]) { int c = Even[j]; Even[j] = Even[j+1]; Even[j+1] = c; } } }
							if (Even.size()==0) { cout << "Answer: there are no even numbers o_0\n"; }
							else if (Even.size()==1) { cout << "Answer: " << Even[0] << "\n"; }
							else { cout << "Answer: " << Even[1] << "\n"; }

					   /* ДЗ5 Динамические одномерные массивы, номер 8.
					   Найдите произведение положительных элементов массива.
					   */
						} else if (chtask=="8") {
							vector <int> A;
							long long int a=1, c=0, sum=0;
							cout << "\nTask 1.\n";
							while (a!=0) {
								cout << "A[" << c << "] = ";
								cin >> a;
								if (a!=0) { A.push_back(a); if (a>0) { sum*=a; }}
								c++;
							}
							cout << "Answer: " << sum << "\n";

						} else if (chtask=="0") { break; }
					}
				} else if (ch5dz=="0") { break; }
			}

		// ДЗ6. Номера от 1 до 7.
		} else if (chdz=="6") {
			while (1) {
				cout << "\n/-------------DZ6 (0 is exit to main menu)--------------\\\n         Write number of task (integer 0-7): ";
				cin >> chtask;
				cout << "\\-------------------------------------------------------/\n";
				
			   /* ДЗ6, номер 1.
			   Реализовать сортировку пузырьком по возрастанию (от наименьшего
			   элемента к наибольшему)
			   */
				if (chtask=="1") {
					int _N;
					cout << "\nN = ";
					cin >> _N;
					const int N = _N;
					int A[N];
					for (int i=0; i<N; i++) {
						cout << "A[" << i << "] = ";
						cin >> A[i];
					}
					for (int i=0; i<N-1; i++) {
						for (int j=N-2; j>=i; j--) {
							if (A[j] > A[j+1]) {
								int c = A[j]; A[j] = A[j+1]; A[j+1] = c;
							}
						}
					}
					cout << "Final list: [";
					for (int i=0;i<N-1;i++) {
						cout << A[i] << ", ";
					}
					cout << A[N-1] << "]\n\n";

			   /* ДЗ6, номер 2.
			   Реализовать сортировку пузырьком по убыванию (от наибольшего
			   элемента к наименьшему)
			   */
				} else if (chtask=="2") {
					int _N;
					cout << "\nN = ";
					cin >> _N;
					const int N = _N;
					int A[N];
					for (int i=0; i<N; i++) {
						cout << "A[" << i << "] = ";
						cin >> A[i];
					}
					for (int i=0; i<N-1; i++) {
						for (int j=N-2; j>=i; j--) {
							if (A[j] < A[j+1]) {
								int c = A[j]; A[j] = A[j+1]; A[j+1] = c;
							}
						}
					}
					cout << "Final list: [";
					for (int i=0;i<N-1;i++) {
						cout << A[i] << ", ";
					}
					cout << A[N-1] << "]\n\n";

			   /* ДЗ6, номер 3.
			   Реализовать сортировку пузырьком, которая заканчивает работу, если
			   на очередном шаге внешнего цикла не было перестановок.
			   */
				} else if (chtask=="3") {
					int _N;
					cout << "\nN = ";
					cin >> _N;
					const int N = _N;
					int A[N];
					for (int i=0; i<N; i++) {
						cout << "A[" << i << "] = ";
						cin >> A[i];
					}
					for (int i=0; i<N-1; i++) {
						int k = 0;
						for (int j=N-2; j>=i; j--) {
							if (A[j] > A[j+1]) {
								k++;
								int c = A[j]; A[j] = A[j+1]; A[j+1] = c;
							}
						}
						if (k==0) { break; }
					}
					cout << "Final list: [";
					for (int i=0;i<N-1;i++) {
						cout << A[i] << ", ";
					}
					cout << A[N-1] << "]\n\n";

			   /* ДЗ6, номер 4.
			   Реализовать сортировку по неубыванию суммы цифр числа.
			   */
				} else if (chtask=="4") {
					int _N;
					long long int n, sum;
					cout << "\nN = ";
					cin >> _N;
					const int N = _N;
					int A[N];
					for (int i=0; i<N; i++) {
						cout << "A[" << i << "] = ";
						cin >> A[i];
					}
					int B[N];
					int I[N];
					int C[N];
					for (int i=0; i<N; i++) {
						sum=0;
						n = A[i];
						while (n!=0) { sum+=n%10; n/=10; }
						B[i] = sum;
						I[i] = i;
					}
					// Сортировка пузырьком по неубыванию.
					for (int i=0; i<N-1; i++) { for (int j=N-2; j>=i; j--) { if (B[j] > B[j+1]) { int c = I[j]; I[j] = I[j+1]; I[j+1] = c; } } }
					for (int i=0; i<N; i++) { C[i] = A[I[i]]; }
					cout << "Final list: [";
					for (int i=0;i<N-1;i++) {
						cout << C[i] << ", ";
					}
					cout << C[N-1] << "]\n\n";

			   /* ДЗ6, номер 5.
			   Расположить по возрастанию все четные элементы массива (нечетные
			   остаются на своих местах, четные расположить по возрастанию).
			   */
				} else if (chtask=="5") {
					int _N;
					int _even, ce=0;
					cout << "\nN = ";
					cin >> _N;
					const int N = _N;
					int A[N];
					for (int i=0; i<N; i++) {
						cout << "A[" << i << "] = ";
						cin >> A[i];
						if (A[i]%2==0) { _even++; }
					}
					const int even = _even;
					int IEven[even];
					for (int i=0; i<N; i++) { if (A[i]%2==0) { IEven[ce]=A[i]; ce++; } }
					for (int i=0; i<even-1; i++) { for (int j=even-2; j>=i; j--) { if (IEven[j] > IEven[j+1]) { int c = IEven[j]; IEven[j] = IEven[j+1]; IEven[j+1] = c; } } }
					int B[N];
					ce=0;
					for (int i=0; i<N; i++) {
						if (A[i]%2==1) { B[i]=A[i]; }
						else { B[i]=IEven[ce]; ce++; }
						cout << i << " " << IEven[ce] << "\n";
					}
					cout << "Final list: [";
					for (int i=0;i<N-1;i++) {
						cout << B[i] << ", ";
					}
					cout << B[N-1] << "]\n\n";

			   /* ДЗ6, номер 6.
			   Массив содержит четное количество элементов. Реализуйте
			   сортировку, где первая половина отсортирована по возрастанию,
			   вторая – по убыванию. Каждый элемент должен остаться в «своей»
			   половине.
			   */
				} else if (chtask=="6") {
					int _N;
					cout << "\nN = ";
					cin >> _N;
					const int N = _N;
					int A[N];
					for (int i=0; i<N; i++) {
						cout << "A[" << i << "] = ";
						cin >> A[i];
					}
					// Две сортировки пузырьком для каждой половины массива.
					for (int i=0; i<N/2; i++) { for (int j=N-2; j>=i; j--) { if (A[j] > A[j+1]) {int c=A[j]; A[j]=A[j+1]; A[j+1]=c; } } }
					for (int i=N/2; i<N; i++) { for (int j=N-2; j>=i; j--) { if (A[j] < A[j+1]) {int c=A[j]; A[j]=A[j+1]; A[j+1]=c; } } }
					cout << "Final list: [";
					for (int i=0;i<N-1;i++) {
						cout << A[i] << ", ";
					}
					cout << A[N-1] << "]\n\n";

			   /* ДЗ6, номер 7.
			   Реализуйте сортировку по возрастанию, которая находит количество
			   различных чисел в массиве.
			   */
				} else if (chtask=="7") {
					int _N;
					long long unsigned int count=0, ic=0;
					cout << "\nN = ";
					cin >> _N;
					const int N = _N;
					int A[N];
					for (int i=0; i<N; i++) {
						cout << "A[" << i << "] = ";
						cin >> A[i];
					}
					for (int i=0; i<N; i++) { 
						ic=0;
						for (int j=i+1; j<N; j++) { 
							// cout << "i=" << i << ", A[i]=" << A[i] << ", j=" << j << ", A[j]=" << A[j] << "\n"; 
							if (A[j]==A[i]) {
								ic++;
								if (ic==1) { count+=2; }
								else { count++; }
							} 
						} 
					}
					for (int i=0; i<N; i++) { for (int j=N-2; j>=i; j--) { if (A[j] > A[j+1]) {int c=A[j]; A[j]=A[j+1]; A[j+1]=c; } } }
					cout << "Answer: " << count << "\n\n";
					cout << "Final list: [";
					for (int i=0;i<N-1;i++) {
						cout << A[i] << ", ";
					}
					cout << A[N-1] << "]\n\n";

				} else if (chtask=="0") { break; }
			}

		// ДЗ7. Номера от 1 до 8.
		} else if (chdz=="7") {
			while (1) {
				cout << "\n/-------------DZ7 (0 is exit to main menu)--------------\\\n         Write number of task (integer 0-8): ";
				cin >> chtask;
				cout << "\\-------------------------------------------------------/\n";
				
			   /* ДЗ7, номер 1.
			   Определить, есть ли заданный символ в заданной строке. На вход
			   даются: строка, искомый символ.
			   */
				if (chtask=="1") {
					while (1) {
						string s;
						bool isHere=false;
						char p;
						cout << "Task 1. String = [type 0 to exit] \n";
						getline(cin, s);
						getline(cin, s);
						if (s=="0") { break; }
						cout << "Symbol = ";
						cin >> p;
						for (long long unsigned int i=0; i<s.size(); i++) {
							if (s[i]==p) { isHere=true; }
						}
						if (isHere) { cout << "\nSymbol IS in this string.\n\n"; }
						else { cout << "\nSymbol is NOT in this string.\n\n"; }
					}

			   /* ДЗ7, номер 2.
			   Определить, сколько раз встречается заданный символ в заданной
			   строке. На вход даются: строка, искомый символ.
			   */
				} else if (chtask=="2") {
					while (1) {
						string s;
						long long unsigned int howmany=0;
						char p;
						cout << "Task 2. String [type 0 to exit] = ";
						getline(cin, s);
						getline(cin, s);
						if (s=="0") { break; }
						cout << "Symbol = ";
						cin >> p;
						for (long long unsigned int i=0; i<s.size(); i++) {
							if (s[i]==p) { howmany++; }
						}
						cout << "\nThere are " << howmany << " symbols in this string.\n\n";
					}

			   /* ДЗ7, номер 3.
			   Заменить в заданной строке исходный символ на заданный. На вход
			   даются: строка, требующий замены символ, заменяющий символ.
			   */
				} else if (chtask=="3") {
					while (1) {
						string s;
						char p1, p2;
						cout << "Task 3. String [type 0 to exit] = ";
						getline(cin, s);
						getline(cin, s);
						if (s=="0") { break; }
						cout << "Symbol 1 = ";
						cin >> p1;
						cout << "Symbol 2 = ";
						cin >> p2;
						for (long long unsigned int i=0; i<s.size(); i++) {
							if (s[i]==p1) { s[i]=p2; }
						}
						cout << "\nString: " << s << "\n\n";
					}

			   /* ДЗ7, номер 4.
			   В заданной строке заменить последовательность символов на
			   заданный символ. На вход даются: строка, требующая замены
			   последовательность, заменяющий символ.
			   */
				} else if (chtask=="4") {
					while (1) {
						string s1, s2;
						char p;
						cout << "Task 4. String 1 [type 0 to exit] = ";
						getline(cin, s1);
						getline(cin, s1);
						if (s1=="0") { break; }
						cout << "String 2 = ";
						getline(cin, s2);
						getline(cin, s2);
						cout << "Symbol = ";
						cin >> p;
						long long unsigned int l=-1;
						while (s.find(p)!=l) {
							int p1 = s.find(p);
							char array = {p};
							string P = "";
							P += array;
							s.erase(p1, s1.size()); s.insert(p1, P);
						}
						cout << "\nString: " << s << "\n\n";
					}

			   /* ДЗ7, номер 5.
			   В заданной строке заменить символ на заданную последовательность.
			   На вход даются: строка, требующий замены символ, заменяющая
			   последовательность.
			   */
				} else if (chtask=="5") {
					while (1) {
						string s1, s2;
						char p;
						cout << "Task 5. String 1 [type 0 to exit] = ";
						getline(cin, s1);
						getline(cin, s1);
						if (s1=="0") { break; }
						cout << "Symbol = ";
						cin >> p;
						cout << "String 2 = ";
						getline(cin, s2);
						getline(cin, s2);
						long long unsigned int l=-1;
						while (s.find(p)!=l) {
							int p1 = s.find(p);
							s.erase(p1, 1); s.insert(p1, s1);
						}
						cout << "\nString: " << s << "\n\n";
					}

			   /* ДЗ7, номер 6.
			   Определить, сколько в заданной строке слов. Между словами может
			   быть не один пробел, в начале и конце строки могут находиться
			   пробелы.
			   */
				} else if (chtask=="6") {
					while (1) {
						int slov=0;
						string s;
						cout << "Task 6. String [type 0 to exit] = ";
						getline(cin, s);
						getline(cin, s);
						if (s=="0") { break; }
						for (int i=0; i<s.size(); i++) {
							if (s[i]==' ' and s[i+1]!=' ') { slov++; }
							if (i==0 and s[i]!=' ') { slov++; }
						}
						cout << "\nAmount of words: " << slov << "\n\n";
					}

			   /* ДЗ7, номер 7.
			   Определить в заданной строке самое длинное слово. Между словами
			   может быть не один пробел, в начале и конце строки могут находиться
			   пробелы.
			   */
				} else if (chtask=="7") {
					while (1) {
						string s;
						string _s="";
						string _biggest="";
						cout << "Task 7. String [type 0 to exit] = ";
						getline(cin, s);
						getline(cin, s);
						if (s=="0") { break; }
						for (int i=0; i<s.size(); i++) {
							if ((s[i]==' ' and s[i+1]!=' ') or (i==0 and s[i]!=' ')) {
								if (_s.size()>_biggest.size()) {
									_biggest = _s;
								}
								_s = s[i+1];
							} else {
								_s += s[i];
							}
						}
						if (_s.size()>_biggest.size()) {
							_biggest = _s;
						}
						cout << "\nBiggest word: " << _biggest << "\n\n";
					}

			   /* ДЗ7, номер 8.
			   Заданная строка содержит адрес файла (например,
			   С:/Фото/2013/Поход/vasya.jpg). Разделить адрес на составляющие
			   (разделитель - /) и каждую часть вывести на экран на новой строке.
			   */
				} else if (chtask=="8") {
					while (1) {
						string s;
						string _s="";
						cout << "Task 8. String [type 0 to exit] = ";
						getline(cin, s);
						getline(cin, s);
						if (s=="0") { break; }
						for (int i=0; i<s.size(); i++) {
							if (s[i]=='/') {
								cout << "\n" << _s;
							} else {
								_s += s[i];
							}
						}
						cout << "\n" << _s << "\n\n";
					}

				} else if (chtask=="0") { break; }
			}

		} else if (chdz=="aperture") { string l, p; cout << "LOGIN: "; cin >> l; if (l=="cjohnson") { cout << "PASSWORD: "; cin >> p; if (p=="tier3") { as=true; } }
		} else if (chdz=="credits") { if (as) s="Program by Alex Kolodchuk and Doug Rattman, 2020.\nI want a good mark :P"; else s="Program by Alex Kolodchuk, 2020."; for (long long unsigned int i=0; i<s.size(); i++) { cout << s[i]; Sleep(100); }
		} else if (chdz=="list") {
			string s = "|========================================================|\n|               Alex Kolodchuk's homework:               |\n|                DZ4: [4, 5, 7, 8]                       |\n|                DZ5:                                    |\n|                 Static [1-8]                           |\n|                 Dynamic one-dm [1-8]                   |\n|                DZ6: [1-7]                              |\n|                DZ7: [1-8]                              |\n|========================================================|\n\n";
			for (long long unsigned int i=0; i<s.size(); i++) { cout << s[i]; Sleep(7); }
		} else if (chdz=="0") { break; }
	}
	return 0;
}
