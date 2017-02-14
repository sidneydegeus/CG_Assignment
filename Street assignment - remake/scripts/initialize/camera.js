/*// camera.js initializes the camera and returns it

define(['threejs'], function($) {


});*/

function initCamera() {
    // Initializing perspective camera. So that object in distance look further away
    // in order to make the scene more realistic for this assignment
    var camera = new THREE.PerspectiveCamera(
        75, // field of view
        window.innerWidth / window.innerHeight, // // aspect — Camera frustum aspect ratio (size of window)
        0.1, // near — Camera frustum near plane.
        10000 // far — Camera frustum far plane.
    );
    // setting position of the camera
    camera.position.x = 0;
    camera.position.y = 5;
    camera.position.z = 10;

    //returns the camera
    return camera;
}