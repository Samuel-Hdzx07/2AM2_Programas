import Footer from "./components/Footer";
import Hero from "./components/Hero";
import Navbar from "./components/Navbar";
import ProductGrid from "./components/ProductGrid";

const Landing = () => {
  return (
    <div className="min-h-screen bg-[#0b0b0b] font-sans text-[#f5f5f5] antialiased">
      <style>{`
        @keyframes fadeIn {
          from { opacity: 0; transform: translateY(10px); }
          to { opacity: 1; transform: translateY(0); }
        }
      `}</style>

      <Navbar />

      <main>
        <Hero />
        <ProductGrid />

        <section
          id="about"
          className="px-6 py-24 text-center md:px-10 [animation:fadeIn_0.8s_ease-out]"
        >
          <p className="mx-auto max-w-3xl text-3xl font-semibold tracking-tight text-[#f5f5f5] md:text-5xl">
            No seguimos tendencias. Las creamos.
          </p>
        </section>
      </main>

      <Footer />
    </div>
  );
};

export default Landing;
