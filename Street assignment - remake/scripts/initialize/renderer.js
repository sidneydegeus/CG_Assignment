/*define(['threejs'], function($){

});*/

function initRenderer() {
    // initRenderer function that initiates all rendere related things
    // Initializing renderer
    var renderer = new THREE.WebGLRenderer({
        antialias: true,
        alpha: true
    });
    // Adding more properties to the renderer
    renderer.setSize(window.innerWidth, window.innerHeight);
    document.body.appendChild(renderer.domElement);

    return renderer;
}

