#include <Eigen/Core>
#include <Eigen/Geometry>
#include <cmath>
#include <iostream>

using namespace std;
using namespace Eigen;

int main(int argc, char **argv) {
    cout << "Hello World!" << endl;
    // 旋转向量
    AngleAxisd rotation_vector(M_PI / 4, Vector3d(0, 0, 1));
    cout << "旋转向量的旋转轴 = " << rotation_vector.axis() << endl;
    cout << "旋转向量的旋转角度 = " << rotation_vector.angle() << endl;
    // 旋转矩阵
    Matrix3d rotation_matrix = Matrix3d::Identity();
    rotation_matrix << 0.707, -0.707, 0, 0.707, 0.707, 0, 0, 0, 1;
    cout << "旋转矩阵 = " << endl << rotation_matrix << endl;

    // 四元数
    Quaterniond q = Quaterniond(0, 0, 0.383, 0.924);
    // (x, y, z, w)
    cout << "四元数 = " << endl << q.coeffs() << endl;
    cout << "四元数 = " << q.x() << " " << q.y() << " " << q.z() << " " << q.w() << endl;

    // 旋转矩阵转换成其他形式
    // 第一种方法
    rotation_vector.fromRotationMatrix(rotation_matrix);
    cout << "旋转向量 = " << endl
         << rotation_vector.angle() << endl
         << rotation_vector.axis() << endl;

    // 第二种方法
    rotation_vector = rotation_matrix;
    cout << "旋转向量 = " << endl
         << rotation_vector.angle() << endl
         << rotation_vector.axis() << endl;

    // 第三种方法
    rotation_vector = AngleAxisd(rotation_matrix);
    cout << "旋转向量 = " << endl
         << rotation_vector.angle() << endl
         << rotation_vector.axis() << endl;

    // 转换成四元数
    // 第一种方法
    q = Quaterniond(rotation_matrix);
    cout << "四元数 = " << endl << q.coeffs() << endl;

    // 第二种方法
    q = rotation_matrix;
    cout << "四元数 = " << endl << q.coeffs() << endl;

    // ...

    return 0;
}
