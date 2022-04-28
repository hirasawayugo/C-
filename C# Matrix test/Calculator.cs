using System;

class Calculator
{
    public double dist( Vector2D vec1, Vector2D vec2 )
    {
        double diff = Math.Sqrt(Math.Pow(vec1.X - vec2.X, 2) + Math.Pow(vec1.Y - vec2.Y, 2));
        return diff;
    }
}