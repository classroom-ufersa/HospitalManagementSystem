function myFunction() {
  var x = document.getElementById("myTopnav");
  if (x.className === "topnav") {
    x.className += " responsive";
  } else {
    x.className = "topnav";
  }
}
// Seleciona todas as caixas
const boxes = document.querySelectorAll(".box");

// Adiciona um evento de clique a cada item da navbar
document.querySelectorAll(".topnav a").forEach((link) => {
  link.addEventListener("click", (event) => {
    // Impede que o link recarregue a página
    event.preventDefault();

    // Obtém o id da box correspondente ao link clicado
    const href = link.getAttribute("href");

    // Obtém a referência à box correspondente
    const box = document.querySelector(href);

    // Faz a tela descer até a box correspondente com animação suave
    box.scrollIntoView({ behavior: "smooth" });
  });
});

