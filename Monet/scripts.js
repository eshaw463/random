document.addEventListener("DOMContentLoaded", () => {
    const slider = document.getElementById("myRange");
    const image = document.getElementById("sliderImage");
    const container = document.getElementById("imageContainer");

    const headerBack = document.getElementById("header");
    const sliderBack = document.getElementById("slideContainer");
    const bodyyy = document.getElementById("body");
    const bodyyy2 = document.getElementById("body2");
    const bodyyy3 = document.getElementById("body3");
    const container2 = document.getElementById("imageContainer2");

    // Array of local image file paths
    const images = ["mm1.png", "mm2.png", "mm3.png", "mm4.png"];

    // Array of background colors
    const colors = ["#BCA6AA", "#E0EDB8", "#D1D9EB", "#D0DEA0"]; // Adjust these to match your preference

    slider.addEventListener("input", () => {
        const index = parseInt(slider.value, 10) - 1;


        image.src = images[index];
        container.style.backgroundColor = colors[index]; // Change background color
        container2.style.backgroundColor = colors[index]; // Change background color
        sliderBack.style.backgroundColor = colors[index]; // Change background color
        headerBack.style.backgroundColor = colors[index]; // Change background color
        bodyyy.style.backgroundColor = colors[index]; // Change background color
        bodyyy2.style.backgroundColor = colors[index]; // Change background color
        bodyyy3.style.backgroundColor = colors[index]; // Change background color
        
       
        

    });
});
