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
}