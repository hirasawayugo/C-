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

    private static Matrix33 mat = new Matrix33(1,0,0, 0,1,0, 0,0,1);

    public static Matrix33 Initialize
    {
        get { return mat; }
    } 

    public static Matrix33 Multiply(Matrix33 matrix1, Matrix33 matrix2)
    {
        Matrix33 result;
        Multiply(ref matrix1, ref matrix2, out result );
        return result;
    }

    public static void Multiply( ref Matrix33 matrix1, ref Matrix33 matrix2, out Matrix33 result )
    {
        result = Matrix33.Initialize;
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

    public static Matrix33 Rotate(float radian)
    {
        Matrix33 result = Matrix33.Initialize;
        var val1 = MathF.Cos(radian);
        var val2 = MathF.Sin(radian);
        
        result.M11 = val1;
        result.M12 = val2;
        result.M21 = -val2;
        result.M22 = val1;
        return result;
    }

    public static void Move(Matrix33 mat, Vector2D vec)
    {
        
        mat.M31 = (float)vec.X;
        mat.M32 = (float)vec.Y;
    }

    public static Vector2D Transform(Matrix33 matrix, Vector2D position)
    {
        return new Vector2D((position.X * matrix.M11) + (position.Y * matrix.M21) + matrix.M31, (position.X * matrix.M12) + (position.Y * matrix.M22) + matrix.M32);
    }

    public static Vector2D operator*(Matrix33 matrix, Vector2D position)
    {
        return Transform(matrix, position);
    }

}