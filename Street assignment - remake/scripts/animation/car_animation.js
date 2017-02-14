// moveCar function handles all the animations for the car movement
function moveCar(cars, planeBox) {
    // moveDirection is 0 because first it has to be determined whether the car moves right or left
    var moveDirection = 0;
    for (var i = 0; i < cars.length; i++) {
        // if a car is driving (true), then make it move direction
        if (cars[i].isDriving) {
            // if the car position is less than the minimum (for example, car position is -50 and end of plane is -45)
            // or if the position is more than the maximum then we'll relocate the car
            // because it moved "off" the plane. so it starts at the other side of the plane
            if(cars[i].carBody.position.x < planeBox.min.x) {
                cars[i].carBody.position.x += planeBox.size().x;
                cars[i].carRoof.position.x += planeBox.size().x;
                cars[i].wheels[0].position.x += planeBox.size().x;
                cars[i].wheels[1].position.x += planeBox.size().x;
                cars[i].wheels[2].position.x += planeBox.size().x;
                cars[i].wheels[3].position.x += planeBox.size().x;
                cars[i].carLights[0].position.x += planeBox.size().x;
                cars[i].carLights[1].position.x += planeBox.size().x;
                cars[i].carSpotlights[0].position.x += planeBox.size().x;
                cars[i].carSpotlights[1].position.x += planeBox.size().x;
                cars[i].carSpotlights[1].lookAt.x  += planeBox.size().x;
            } else if (cars[i].carBody.position.x > planeBox.max.x) {
                cars[i].carBody.position.x -= planeBox.size().x;
                cars[i].carRoof.position.x -= planeBox.size().x;
                cars[i].wheels[0].position.x -= planeBox.size().x;
                cars[i].wheels[1].position.x -= planeBox.size().x;
                cars[i].wheels[2].position.x -= planeBox.size().x;
                cars[i].wheels[3].position.x -= planeBox.size().x;
                cars[i].carLights[0].position.x -= planeBox.size().x;
                cars[i].carLights[1].position.x -= planeBox.size().x;
                cars[i].carSpotlights[0].position.x -= planeBox.size().x;
                cars[i].carSpotlights[1].position.x -= planeBox.size().x;
                cars[i].carSpotlights[1].lookAt.x  -= planeBox.size().x;
            }
            // move the x position of all components of the car
            cars[i].direction ? moveDirection = 0.03 : moveDirection = -0.03;
            cars[i].carBody.position.x += moveDirection;
            cars[i].carRoof.position.x += moveDirection;
            cars[i].wheels[0].position.x += moveDirection;
            cars[i].wheels[1].position.x += moveDirection;
            cars[i].wheels[2].position.x += moveDirection;
            cars[i].wheels[3].position.x += moveDirection;
            cars[i].carLights[0].position.x += moveDirection;
            cars[i].carLights[1].position.x += moveDirection;
            cars[i].carSpotlights[0].position.x += moveDirection;
            cars[i].carSpotlights[1].position.x += moveDirection;
            cars[i].carSpotlights[1].lookAt.x += moveDirection;
        }
    }
}