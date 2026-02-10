//Axel Roberto Fores Moreno
#include <iostream>
#include <iomanip>
using namespace std;

class Rect {
public:
    float X, Y, Alto, Ancho;

    Rect() : X(0), Y(0), Alto(0), Ancho(0) {}
    Rect(float x, float y, float alto, float ancho) : X(x), Y(y), Alto(alto), Ancho(ancho) {}
    Rect(float alto, float ancho) : X(0), Y(0), Alto(alto), Ancho(ancho) {}

    bool ImprimirYCacularFinales(const Rect& r, float& xFinal, float& yFinal) const {
        cout << "[Rect] Recibido: X=" << r.X << ", Y=" << r.Y << ", Alto=" << r.Alto << ", Ancho=" << r.Ancho << "\n";
        if (r.X < 0 || r.Y < 0 || r.Alto < 0 || r.Ancho < 0) return false;
        xFinal = r.X + r.Ancho;
        yFinal = r.Y + r.Alto;
        cout << "  -> Fin en (" << xFinal << ", " << yFinal << ")\n";
        return true;
    }

    static bool CheckOverlap(const Rect& A, const Rect& B) {
        bool noOverlap = (A.X + A.Ancho <= B.X) || (B.X + B.Ancho <= A.X) ||
                         (A.Y + A.Alto <= B.Y) || (B.Y + B.Alto <= A.Y);
        return !noOverlap;
    }
};

int main() {
    Rect r1(0,0,5,5);
    Rect r2(6,6,5,5);
    Rect r3(2,2,2,2);
    cout << "r1 y r2 se traslapan? " << (Rect::CheckOverlap(r1,r2)?"SI":"NO") << "\n";
    cout << "r1 y r3 se traslapan? " << (Rect::CheckOverlap(r1,r3)?"SI":"NO") << "\n";
    return 0;
}
