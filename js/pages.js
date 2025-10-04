function JumpTo(link, id) {
    window.location.href = link + "#" + id;
}

window.addEventListener("load", function () {
  const header = document.querySelector(".news-header");
  const content = document.getElementById("content");

  if (header && content) {
    const headerHeight = header.offsetHeight;
    content.style.marginTop = headerHeight + "px";
  }
});

document.addEventListener("DOMContentLoaded", function () {
  const toggleBtn = document.getElementById("toggle-comments");
  const collapseDiv = document.querySelector(".news-comments .collapse");

  toggleBtn.addEventListener("click", function () {
    collapseDiv.style.display =
      collapseDiv.style.display === "block" ? "none" : "block";
  });
});
