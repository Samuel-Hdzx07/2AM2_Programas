const ProductCard = ({ tag, name, price }) => {
  return (
    <article className="group rounded-2xl border border-[#262626] bg-[#111111] p-6 transition-all duration-300 hover:scale-[1.02] hover:border-[#c2b280]/60">
      <span className="inline-flex rounded-full border border-[#3a3a3a] px-3 py-1 text-xs uppercase tracking-widest text-[#9ca3af]">
        {tag}
      </span>
      <h3 className="mt-8 text-2xl font-semibold text-[#f5f5f5]">{name}</h3>
      <p className="mt-3 text-sm text-[#9ca3af]">{price}</p>
    </article>
  );
};

export default ProductCard;
