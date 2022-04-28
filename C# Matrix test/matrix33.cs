using System;
using System.Runtime.Serialization;
[DataContract]
class Matrix33
{
    public Matrix33( float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33 ){
        M11 = m11;
        M12 = m12;
        M13 = m13;
        M21 = m21;
        M22 = m22;
        M23 = m23;
        M31 = m31;
        M32 = m32;
        M33 = m33; 
    }
    [DataMember]
    public float M11;
    [DataMember]
    public float M12;
    [DataMember]
    public float M13;
    [DataMember]
    public float M21;
    [DataMember]
    public float M22;
    [DataMember]
    public float M23;
    [DataMember]
    public float M31;
    [DataMember]
    public float M32;
    [DataMember]
    public float M33;
    
    public float this[int index]{
        get
        {
            switch(index){
                case 0: return M11;
                case 1: return M12;
                case 2: return M13;
                case 3: return M21;
                case 4: return M22;
                case 5: return M23;
                case 6: return M31;
                case 7: return M32;
                case 8: return M33;
            }
            return 0;
        }
        set
        {
             switch(index){
                case 0: M11 = value; break;
                case 1: M12 = value; break;
                case 2: M13 = value; break;
                case 3: M21 = value; break;
                case 4: M22 = value; break;
                case 5: M23 = value; break;
                case 6: M31 = value; break;
                case 7: M32 = value; break;
                case 8: M33 = value; break;
            }
        }
    }
    public float this[int row, int column]
    {
        get
        {
            return this[(row * 4) + column];
        }

        set
        {
            this[(row * 4) + column] = value;
        }
    }

    public static Matrix33 Multiply(Matrix33 matrix1, Matrix33 matrix2)
    {
        Matrix33 result = new Matrix33(0,0,0,0,0,0,0,0,0);
        var m11 = ((matrix1.M11 * matrix2.M11) + (matrix1.M12 * matrix2.M21)) + (matrix1.M13 * matrix2.M31);
        var m12 = ((matrix1.M11 * matrix2.M12) + (matrix1.M12 * matrix2.M22)) + (matrix1.M13 * matrix2.M32);
        var m13 = ((matrix1.M11 * matrix2.M13) + (matrix1.M12 * matrix2.M23)) + (matrix1.M13 * matrix2.M33);
        var m21 = ((matrix1.M21 * matrix2.M11) + (matrix1.M22 * matrix2.M21)) + (matrix1.M23 * matrix2.M31);
        var m22 = ((matrix1.M21 * matrix2.M12) + (matrix1.M22 * matrix2.M22)) + (matrix1.M23 * matrix2.M32);
        var m23 = ((matrix1.M21 * matrix2.M13) + (matrix1.M22 * matrix2.M23)) + (matrix1.M23 * matrix2.M33);
        var m31 = ((matrix1.M31 * matrix2.M11) + (matrix1.M32 * matrix2.M21)) + (matrix1.M33 * matrix2.M31);
        var m32 = ((matrix1.M31 * matrix2.M12) + (matrix1.M32 * matrix2.M22)) + (matrix1.M33 * matrix2.M32);
        var m33 = ((matrix1.M31 * matrix2.M13) + (matrix1.M32 * matrix2.M23)) + (matrix1.M33 * matrix2.M33);
        result.M11 = m11;
        result.M12 = m12;
        result.M13 = m13;
        result.M21 = m21;
        result.M22 = m22;
        result.M23 = m23;
        result.M31 = m31;
        result.M32 = m32;
        result.M33 = m33;
        return result;
    }

    public static void Multiply( ref Matrix33 matrix1, ref Matrix33 matrix2, ref Matrix33 result )
    {
        var m11 = ((matrix1.M11 * matrix2.M11) + (matrix1.M12 * matrix2.M21)) + (matrix1.M13 * matrix2.M31);
        var m12 = ((matrix1.M11 * matrix2.M12) + (matrix1.M12 * matrix2.M22)) + (matrix1.M13 * matrix2.M32);
        var m13 = ((matrix1.M11 * matrix2.M13) + (matrix1.M12 * matrix2.M23)) + (matrix1.M13 * matrix2.M33);
        var m21 = ((matrix1.M21 * matrix2.M11) + (matrix1.M22 * matrix2.M21)) + (matrix1.M23 * matrix2.M31);
        var m22 = ((matrix1.M21 * matrix2.M12) + (matrix1.M22 * matrix2.M22)) + (matrix1.M23 * matrix2.M32);
        var m23 = ((matrix1.M21 * matrix2.M13) + (matrix1.M22 * matrix2.M23)) + (matrix1.M23 * matrix2.M33);
        var m31 = ((matrix1.M31 * matrix2.M11) + (matrix1.M32 * matrix2.M21)) + (matrix1.M33 * matrix2.M31);
        var m32 = ((matrix1.M31 * matrix2.M12) + (matrix1.M32 * matrix2.M22)) + (matrix1.M33 * matrix2.M32);
        var m33 = ((matrix1.M31 * matrix2.M13) + (matrix1.M32 * matrix2.M23)) + (matrix1.M33 * matrix2.M33);
        result.M11 = m11;
        result.M12 = m12;
        result.M13 = m13;
        result.M21 = m21;
        result.M22 = m22;
        result.M23 = m23;
        result.M31 = m31;
        result.M32 = m32;
        result.M33 = m33;
    }

    public static Matrix33 operator*( Matrix33 matrix1, Matrix33 matrix2){
        return Multiply( matrix1, matrix2);
    }

    public static Matrix33 Multply( Matrix33 matrix1, float scaleFactor ){
        matrix1.M11 *= scaleFactor;
        matrix1.M12 *= scaleFactor;
        matrix1.M13 *= scaleFactor;
        matrix1.M21 *= scaleFactor;
        matrix1.M22 *= scaleFactor;
        matrix1.M23 *= scaleFactor;
        matrix1.M31 *= scaleFactor;
        matrix1.M32 *= scaleFactor;
        matrix1.M33 *= scaleFactor;
        return matrix1;
    }

}