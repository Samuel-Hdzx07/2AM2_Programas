const Hero = () => {
  return (
    <section
      id="inicio"
      className="relative grid min-h-screen items-center gap-16 overflow-hidden px-6 pb-20 pt-28 md:grid-cols-2 md:px-10"
    >
      <span className="pointer-events-none absolute right-6 top-1/2 -translate-y-1/2 text-[12rem] font-black leading-none text-[#f5f5f5]/[0.05] md:right-12 md:text-[20rem]">
        24
      </span>

      <div className="relative z-10 max-w-xl [animation:fadeIn_0.8s_ease-out]">
        <p className="mb-6 text-xs font-medium uppercase tracking-[0.35em] text-[#c2b280]">
          Colección 2025
        </p>
        <h1 className="text-6xl font-black uppercase leading-[0.88] tracking-tight text-[#f5f5f5] md:text-8xl">
          <span className="block">Tus</span>
          <span
            className="block text-transparent"
            style={{ WebkitTextStroke: "1.5px #f5f5f5" }}
          >
            Playeras
          </span>
          <span className="block">Aquí</span>
        </h1>
        <p className="mt-8 max-w-md text-base leading-relaxed text-[#9ca3af]">
          Piezas limitadas para quienes no piden permiso. Diseño universitario,
          actitud de calle y detalle premium.
        </p>
        <div className="mt-10 flex flex-col gap-4 sm:flex-row">
          <a
            href="#shop"
            className="inline-flex items-center justify-center rounded-full border border-[#c2b280] bg-[#c2b280] px-7 py-3 text-sm font-medium text-black transition-transform duration-300 hover:scale-[1.03]"
          >
            Ver colección
          </a>
          <a
            href="#about"
            className="inline-flex items-center justify-center rounded-full border border-[#2c2c2c] px-7 py-3 text-sm font-medium text-[#f5f5f5] transition-all duration-300 hover:scale-[1.03] hover:border-[#c2b280] hover:text-[#c2b280]"
          >
            Mi marca
          </a>
        </div>
      </div>
    </section>
  );
};

export default Hero;
