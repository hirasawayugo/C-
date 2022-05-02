using System.Runtime.Serialization;

[DataContract]
public struct Vector2D
{
    [DataMember]
    public double X;

    [DataMember]
    public double Y;

    public Vector2D(double x, double y)
    {
        this.X = x;
        this.Y = y;
    }

    public static Vector2D add( Vector2D vec1, Vector2D vec2 )
    {
        Vector2D addVec;
        addVec.X = vec1.X + vec2.X;
        addVec.Y = vec1.Y + vec2.Y;
        return addVec;
    }

    public static Vector2D operator+( Vector2D vec1, Vector2D vec2 )
    {
        return add(vec1, vec2);
    }

    public static Vector2D Transform(Vector2D position, Matrix33 matrix)
    {
        return new Vector2D((position.X * matrix.M11) + (position.Y * matrix.M21) + matrix.M31, (position.X * matrix.M12) + (position.Y * matrix.M22) + matrix.M32);
    }

    public static Vector2D operator*(Vector2D position, Matrix33 matrix)
    {
        return Transform( position, matrix);
    }
}