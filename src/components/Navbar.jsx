import { useEffect, useState } from "react";

const Navbar = () => {
  const [scrolled, setScrolled] = useState(false);

  useEffect(() => {
    const onScroll = () => setScrolled(window.scrollY > 16);
    onScroll();
    window.addEventListener("scroll", onScroll);
    return () => window.removeEventListener("scroll", onScroll);
  }, []);

  return (
    <header
      className={`fixed inset-x-0 top-0 z-50 transition-all duration-300 ${
        scrolled ? "bg-black/70 backdrop-blur-md" : "bg-transparent"
      }`}
    >
      <nav className="mx-auto flex h-20 w-full max-w-7xl items-center justify-between px-6 md:px-10">
        <a
          href="#inicio"
          className="text-lg font-semibold tracking-[0.3em] text-[#f5f5f5]"
        >
          DROPOUT
        </a>
        <ul className="flex items-center gap-6 text-sm text-[#9ca3af] md:gap-8">
          {["Inicio", "Shop", "Carrito"].map((item) => (
            <li key={item}>
              <a
                href={`#${item.toLowerCase()}`}
                className="transition-colors duration-300 hover:text-[#c2b280]"
              >
                {item}
              </a>
            </li>
          ))}
        </ul>
      </nav>
    </header>
  );
};

export default Navbar;
