// Karen Garduño

#include <iostream>
using namespace std;


//  EJERCICIO 2: CLASE Rect

class Rect {
private:
    float x, y, alto, ancho;

public:
    Rect() : x(0), y(0), alto(0), ancho(0) {}
    Rect(float px, float py, float pAlto, float pAncho) : x(px), y(py), alto(pAlto), ancho(pAncho) {}
    Rect(float pAlto, float pAncho) : x(0), y(0), alto(pAlto), ancho(pAncho) {}

    bool ImprimirYCalcularFinales(Rect& r, float& finalX, float& finalY) {
        cout << "\nDatos del Rect recibido:" << endl;
        cout << "X: " << r.x << "  Y: " << r.y << "  Alto: " << r.alto << "  Ancho: " << r.ancho << endl;
        if (r.x < 0 || r.y < 0 || r.alto < 0 || r.ancho < 0) return false;
        finalX = r.x + r.ancho;
        finalY = r.y + r.alto;
        cout << "Rect inicia en (" << r.x << ", " << r.y << ")" << endl;
        cout << "Rect termina en (" << finalX << ", " << finalY << ")" << endl;
        return true;
    }

    static bool CheckOverlap(const Rect& a, const Rect& b) {
        float ax1 = a.x, ay1 = a.y;
        float ax2 = a.x + a.ancho, ay2 = a.y + a.alto;
        float bx1 = b.x, by1 = b.y;
        float bx2 = b.x + b.ancho, by2 = b.y + b.alto;
        if (ax2 <= bx1 || bx2 <= ax1 || ay2 <= by1 || by2 <= ay1)
            return false;
        return true;
    }

    void imprimir() const {
        cout << "Rect [x=" << x << ", y=" << y << ", alto=" << alto << ", ancho=" << ancho << "]" << endl;
    }
};

int main() {
    Rect r1(0, 0, 5, 5);
    Rect r2(2, 2, 2, 2);
    Rect r3(6, 6, 5, 5);
    float fx, fy;
    r1.ImprimirYCalcularFinales(r2, fx, fy);
    cout << "¿r1 y r2 se traslapan? " << (Rect::CheckOverlap(r1, r2) ? "Sí" : "No") << endl;
    cout << "¿r1 y r3 se traslapan? " << (Rect::CheckOverlap(r1, r3) ? "Sí" : "No") << endl;
    return 0;
}
