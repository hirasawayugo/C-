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
        vec1.X += vec2.X;
        vec1.Y += vec2.Y;
        return vec1;
    }

    public static Vector2D operator+( Vector2D vec1, Vector2D vec2 )
    {
        return add(vec1, vec2);
    }
}