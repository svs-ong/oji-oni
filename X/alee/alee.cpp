// struct Car
// {
//     float mass;
//     int maxSpeed;
// }

// void increaseSpeed(Car *car)

// {
//     car->maxSpeed++;
// }
void main()
{
    Car c = {0.0f, 250};
    increaseSpeed(&c);
    printf("%d", c.maxSpeed);
}

class Car
{
public:
    Car(/* args */);
    ~Car();
    float mass;
    int maxSpeed;
    increaseSpeed(){
        this->maxSpeed++;
    }
};

Car::Car(    float mass,int maxSpeed)
{
    this->mass = mass;
    this->maxSpeed = maxSpeed;
}

Car::~Car()
{
}

void main(){
    Car c(0.0f, 250);
    c.increaseSpeed();
    cout << c.maxSpeed;
}
