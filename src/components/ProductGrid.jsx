import ProductCard from "./ProductCard";

const products = [
  { tag: "Nuevo", name: "Drop 01", price: "$899 MXN" },
  { tag: "Limitado", name: "Vintage", price: "$999 MXN" },
  { tag: "Popular", name: "Classic", price: "$799 MXN" },
];

const ProductGrid = () => {
  return (
    <section id="shop" className="px-6 py-20 md:px-10 md:py-24">
      <div className="mx-auto w-full max-w-7xl [animation:fadeIn_0.8s_ease-out]">
        <h2 className="text-3xl font-bold uppercase tracking-tight text-[#f5f5f5] md:text-4xl">
          Featured Products
        </h2>
        <p className="mt-3 text-sm text-[#9ca3af]">
          Selección curada para los que van primero.
        </p>
        <div className="mt-10 grid gap-6 md:grid-cols-3">
          {products.map((product) => (
            <ProductCard key={product.name} {...product} />
          ))}
        </div>
      </div>
    </section>
  );
};

export default ProductGrid;
