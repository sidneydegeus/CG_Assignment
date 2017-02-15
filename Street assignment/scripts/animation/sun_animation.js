// moveSun function handles all animations for the sun
function moveSun(sun, time, delta) {
    sun.position.z = Math.cos(time) * 20.5;
    sun.position.y = Math.sin(time) * 20.5;
    sun.rotation.x += 6.4 * delta;
}