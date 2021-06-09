int Trigger = 11;   //Pin digital 2 para el Trigger del sensor
int Echo = 12;   //Pin digital 3 para el Echo del sensor
int motor = 2;

void setup()
{
    Serial.begin(9600);//iniciailzamos la comunicación
    pinMode(Trigger, OUTPUT); //pin como salida
    pinMode(Echo, INPUT);  //pin como entrada
    pinMode(motor, OUTPUT);
    digitalWrite(motor, LOW);
    digitalWrite(Trigger, LOW);//Inicializamos el pin con 0

}

void loop()
{
    long t; //timepo que demora en llegar el eco
    long d; //distancia en centimetros
    {
        if (Serial.available() > 0) {
            String info;
            info = Serial.readStringUntil('\n');
        }
    digitalWrite(Trigger, HIGH);
    delayMicroseconds(10);          //Enviamos un pulso de 10us
    digitalWrite(Trigger, LOW);

    t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
    d = t / 59;             //escalamos el tiempo a una distancia en cm

    Serial.print("Distancia: ");
    Serial.print(d);      //Enviamos serialmente el valor de la distancia
    Serial.print("cm");
    Serial.println();
    delay(100);          //Hacemos una pausa de 100ms

    if ((d) >= 100) {
        digitalWrite(motor, HIGH);
    }
    else if (d < 100) {
        digitalWrite(motor, LOW);

    }
}
