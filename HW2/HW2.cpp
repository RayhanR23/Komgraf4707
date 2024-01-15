#include <iostream>

using namespace std;

int i, j;
int m1[2][2], m2[2][2], h[2][2];

void penjumlahan(int m1[2][2], int m2[2][2])
{
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            h[i][j] = m1[i][j] + m2[i][j];
            cout << h[i][j] << " ";
        }
        cout << endl;
    }
}
void pengurangan(int m1[2][2], int m2[2][2])
{
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            h[i][j] = m1[i][j] - m2[i][j];
            cout << h[i][j] << " ";
        }
        cout << endl;
    }
}

void perkalianAntarMatriks(int m1[2][2], int m2[2][2])
{
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            h[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                h[i][j] += m1[i][k] * m2[k][j];
            }
            cout << h[i][j] << " ";
        }
        cout << endl;
    }
}

void perkalianSkalar(int m1[2][2], int m2[2][2])
{
    int n;
    int h1[2][2], h2[2][2];
    n = 2;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            h1[i][j] = m1[i][j] * n;
            h2[i][j] = m2[i][j] * n;
                                    
        }
    }
    cout << "Hasil perkalian skalar matriks 1" << endl;
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++)
        {
            cout << h1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Hasil perkalian skalar matriks 2" << endl;
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++)
        {
            cout << h2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int main()
{
    cout << "Mengisi nilai dari matriks pertama " << endl;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cout << "Masukkan nilai untuk matriks 1 baris [" << i + 1 << "] dan kolom [" << j + 1 << "]" << endl;
            cin >> m1[i][j];
        }
    }

    cout << "Mengisi nilai dari matriks kedua " << endl;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cout << "Masukkan nilai untuk matriks 2 baris [" << i + 1 << "] dan kolom [" << j + 1 << "]" << endl;
            cin >> m2[i][j];
        }
    }
    cout << endl;

    cout << "Matriks 1 :" <<endl;
    for (i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            cout << m1[i][j] << " ";            
        }
        cout << endl;
    }
    cout << endl;

    cout << "Matriks 2 :" <<endl;
    for (i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            cout << m2[i][j] << " ";            
        }
        cout << endl;
    }
    cout << endl;

    // Melakukan penjumlahan matriks
    cout << "Hasil penjumlahan matriks :" << endl;
    penjumlahan(m1, m2);
    cout << endl;

    cout <<"Hasil pengurangan matriks :" << endl;
    pengurangan(m1, m2);
    cout << endl;

    cout <<"Hasil perkalian antar matriks :" << endl;
    perkalianAntarMatriks(m1, m2);
    cout << endl;

    cout <<"Hasil perkalian skalar matriks :" << endl;
    perkalianSkalar(m1, m2);
    cout << endl;

    return 0;
}
